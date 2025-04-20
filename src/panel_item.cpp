#include "panel_item.h"

#include "explorer.h"
#include "../styles/styles.h"

#include <QFile>

#include <iostream>

PanelItem::PanelItem(QWidget* parent, int panel_width, int panel_elements_size) : Widget(parent)
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
    y += SROLL_SPEED;

    this->setGeometry(0, y, w, h);
}

void PanelItem::scroll_down()
{
    y -= SROLL_SPEED;

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
        Explorer::explorer_current_file_data = current_file.readAll();
        current_file.close();

        std::cout << Explorer::explorer_current_file_data.toStdString() << std::endl;
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