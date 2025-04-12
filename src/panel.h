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
    int                         elements_size() const { return this->items.size(); }


protected:
    void                        wheelEvent(QWheelEvent* event) override;

    
private:
    std::vector<PanelItem *>    items;

};

#endif // PANEL_H