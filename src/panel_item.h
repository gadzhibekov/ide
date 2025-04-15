#ifndef PANEL_ITEM_H
#define PANEL_ITEM_H

#define PANEL_ITEM_SIZE 50
#define SROLL_SPEED     20

#include "ui/label.h"
#include "ui/button.h"

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QEvent>
#include <QMouseEvent>

struct PanelItem : QWidget
{
    PanelItem(QWidget* parent, int panel_width, int panel_elements_size);

    void        set_file(const QString& path);
    void        set_geometry(int x, int y, int w, int h);

    Label*      get_icon()   const   { return this->icon; }
    Label*      get_file()   const   { return this->file; }

    void        scroll_up();
    void        scroll_down();

    int         x;
    int         y;
    int         w;
    int         h;

protected:
    void        mousePressEvent(QMouseEvent* event)         override;
    void        mouseDoubleClickEvent(QMouseEvent *event)   override;
    void        enterEvent(QEvent *event)                   override;
    void        leaveEvent(QEvent *event)                   override;

private:
    Label*      icon;
    Label*      file;
};

#endif // PANEL_ITEM_H