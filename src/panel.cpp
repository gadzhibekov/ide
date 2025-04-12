#include "panel.h"

#include <iostream>

Panel::Panel(QWidget* parent, int width, int height) : QWidget(parent)
{
    this->setGeometry(0, 0, width, height);
    this->setStyleSheet("background-color: gray;");
}

void Panel::add_item(PanelItem* panel_item)
{
    items.push_back(panel_item);
    panel_item->show();
}

void Panel::wheelEvent(QWheelEvent* event)
{
    for (auto item : items)
    {
        if (event->angleDelta().y() > 0)
        {
            item->scroll_up();
        }
        else
        {
            item->scroll_down();
        }
    }
    
    QWidget::wheelEvent(event);
}

void Panel::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}