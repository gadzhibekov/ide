#ifndef PANEL_H
#define PANEL_H

#include "panel_item.h"
#include "ui/button.h"
#include "ui/widget.h"

#include <QWidget>
#include <QEvent>
#include <QWheelEvent>

#include <vector>

struct Panel : Widget
{
    Panel(QWidget* parent, int width, int height);

    void                        add_item(PanelItem* panel_item);
    void                        set_geometry(int x, int y, int w, int h)                override;
    void                        remove_all();
    int                         elements_size() const { return this->items.size(); }
    std::vector<PanelItem *>&   get_items_vector() { return this->items; }
    int                         width;
    int                         height;

protected:
    void                        wheelEvent(QWheelEvent* event)                          override;

    
private:
    std::vector<PanelItem *>    items;
};

#endif // PANEL_H