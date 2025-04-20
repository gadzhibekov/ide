#include "panel.h"

#include <iostream>

Panel::Panel(QWidget* parent, int width, int height) : Widget(parent), width(width), height(height)
{
    this->setGeometry(0, 20, width, height);
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
        if (event->angleDelta().y() > 0)    item->scroll_up();
        else                                item->scroll_down();
    }
    
    QWidget::wheelEvent(event);
}

void Panel::set_geometry(int x, int y, int w, int h)
{
    width   = w;
    height  = h;

    this->setGeometry(x, y, w, h);
}

void Panel::remove_all()
{
    if (items.size() == 0) return;

    for (auto ptr : items)
    {
        if (!ptr) continue;
        
        delete ptr;
        ptr = nullptr;
    }

    items.clear();
}