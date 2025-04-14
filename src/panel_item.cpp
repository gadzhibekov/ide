#include "panel_item.h"

#include "explorer.h"

#include <QFile>

#include <iostream>

PanelItem::PanelItem(QWidget* parent, int panel_width, int panel_elements_size) : QWidget(parent)
{
    icon    = new Label(this);
    file    = new Label(this);

    icon->setAlignment(Qt::AlignVCenter);
    file->setAlignment(Qt::AlignVCenter);
    
    x = 0;
    y = panel_elements_size * PANEL_ITEM_SIZE;
    w = panel_width;
    h = PANEL_ITEM_SIZE;

    this->setGeometry(x, y, w * 1000, h);
    icon->setGeometry(0, 5, h, h);
    file->setGeometry(h, 0, (w - h) * 1000, h);

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

void PanelItem::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
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
    QFile current_file(file->text());

    if (current_file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        Explorer::explorer_current_file_data = current_file.readAll();
        current_file.close();
    }

    std::cout << Explorer::explorer_current_file_data.toStdString() << std::endl;

    QWidget::mouseDoubleClickEvent(event); 
}

void PanelItem::enterEvent(QEvent* event)
{
    std::cout << "Enter: " << file->text().toStdString() << std::endl;

    QWidget::enterEvent(event);
}

void PanelItem::leaveEvent(QEvent* event) 
{
    std::cout << "Leave: " << file->text().toStdString() << std::endl;

    QWidget::leaveEvent(event);
}