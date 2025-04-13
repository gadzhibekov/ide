#include "panel_item.h"

#include "explorer.h"

#include <iostream>

PanelItem::PanelItem(QWidget* parent, int panel_width, int panel_elements_size) : QWidget(parent)
{
    icon    = new Label(this);
    file    = new Label(this);
    
    x = 0;
    y = panel_elements_size * PANEL_ITEM_SIZE;
    w = panel_width;
    h = PANEL_ITEM_SIZE;

    this->setGeometry(x, y, w * 1000, h);
    icon->setGeometry(0, 0, h, h);
    file->setGeometry(h, 0, (w - h) * 1000, h);

    this->hide();
}

void PanelItem::set_icon(const QString& path)
{
    icon->setText(path);
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
        Explorer::explorer_file = file->get_text();
    }
    
    QWidget::mousePressEvent(event); 
}