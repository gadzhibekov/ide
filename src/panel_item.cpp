#include "panel_item.h"
#include "utils/explorer.h"
#include "../styles/styles.h"

#include <QFile>
#include <QTextStream>

#include <iostream>

PanelItem::PanelItem(QWidget* parent, Redactor* redactor, int panel_width, int panel_elements_size) 
: Widget(parent), redactor(redactor)
{
    icon    = new Label(this);
    file    = new Label(this);

    icon->setAlignment(Qt::AlignVCenter);
    file->setAlignment(Qt::AlignVCenter);

    icon->set_text_color(255, 255, 255);
    file->set_text_color(255, 255, 255);

    icon->set_style(PANEL_TOOLS_ITEM_LABEL_STYLE_PATH);
    file->set_style(PANEL_TOOLS_ITEM_LABEL_STYLE_PATH);
    
    x = 0;
    y = panel_elements_size * PANEL_ITEM_SIZE;
    w = panel_width;
    h = PANEL_ITEM_SIZE;

    this->set_geometry(x, y, w * 1000, h);
    icon->setGeometry(5, 5, h, h - 5);
    file->setGeometry(h, 5, (w - h) * 1000, h - 10);

    this->set_style(PANEL_TOOLS_ITEM_STYLE_PATH);
    this->hide();
}

void PanelItem::set_file(const QString& path)
{
    file->setText(path);
}

void PanelItem::scroll_up()
{
    y += PANEL_SROLL_SPEED;

    this->setGeometry(0, y, w, h);
}

void PanelItem::scroll_down()
{
    y -= PANEL_SROLL_SPEED;

    this->setGeometry(0, y, w, h);
}

void PanelItem::set_panel_items_vector(std::vector<PanelItem *>& items)
{
    this->items = items;
}

void PanelItem::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        Explorer::explorer_current_file = file->get_text();
    }
    
    QWidget::mousePressEvent(event); 
}

void PanelItem::mouseDoubleClickEvent(QMouseEvent* event)
{
    update_items_style();
    Explorer::explorer_current_file = file->text();
    this->set_style(PANEL_TOOLS_ITEM_DOBLE_CLICK_STYLE_PATH);

    QFile current_file(file->text());

    if (current_file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        redactor->remove_all();

        Explorer::explorer_current_file_data.clear();

        QTextStream in(&current_file);

        while (!in.atEnd()) Explorer::explorer_current_file_data.push_back(in.readLine());

        current_file.close();

        for (int i = 0; i < Explorer::explorer_current_file_data.size(); ++i)
        {
            RedactorItem* redactor_item = new RedactorItem(redactor, redactor->width(), redactor->get_items_vector().size());

            redactor_item->set_index(static_cast<unsigned int>(i + 1));
            redactor_item->set_line(Explorer::explorer_current_file_data[i]);
            redactor_item->set_button_text_size(Redactor::item_text_size);
            redactor_item->set_line_text_size(Redactor::item_text_size);

            redactor->add_item(redactor_item);
        }

    }

    QWidget::mouseDoubleClickEvent(event); 
}

void PanelItem::enterEvent(QEvent* event)
{
    this->set_style(PANEL_TOOLS_ITEM_CLICK_STYLE_PATH);

    QWidget::enterEvent(event);
}

void PanelItem::leaveEvent(QEvent* event) 
{
    if (Explorer::explorer_current_file == file->get_text())
    {
        this->set_style(PANEL_TOOLS_ITEM_DOBLE_CLICK_STYLE_PATH);
    }
    else
    {
        this->set_style(PANEL_TOOLS_ITEM_STYLE_PATH);
    }

    QWidget::leaveEvent(event);
}

void PanelItem::update_items_style()
{
    for (int i = 0; i < items.size(); ++i)
    {
        items[i]->set_style(PANEL_TOOLS_ITEM_STYLE_PATH);
    }
}