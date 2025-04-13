#ifndef PANEL_H
#define PANEL_H

#include "panel_item.h"
#include "ui/button.h"

#include <QWidget>
#include <QEvent>
#include <QWheelEvent>

#include <vector>

struct Panel : QWidget
{
    Panel(QWidget* parent, int width, int height);
    ~Panel() = default;

    void                        add_item(PanelItem* panel_item);
    void                        set_geometry(int x, int y, int w, int h);
    void                        remove_all();
    int                         elements_size() const { return this->items.size(); }
    std::vector<PanelItem *>    get_items_vector() const { return this->items; }
    int                         width;
    int                         height;

protected:
    void                        wheelEvent(QWheelEvent* event) override;

    
private:
    std::vector<PanelItem *>    items;
};

#endif // PANEL_H