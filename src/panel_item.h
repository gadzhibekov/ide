#ifndef PANEL_ITEM_H
#define PANEL_ITEM_H

#define PANEL_ITEM_SIZE 50
#define SROLL_SPEED     20

#include "ui/label.h"

#include <QWidget>
#include <QLabel>
#include <QString>

struct PanelItem : QWidget
{
    PanelItem(QWidget* parent, int panel_width, int panel_elements_size);
    ~PanelItem() = default;

    void        set_icon(const QString& path);
    void        set_file(const QString& path);

    Label*      get_icon()  const   { return this->icon; }
    Label*      get_file()  const   { return this->file; }

    void        scroll_up();
    void        scroll_down();

    int         x;
    int         y;
    int         w;
    int         h;

    
private:
    Label*      icon;
    Label*      file;
};

#endif // PANEL_ITEM_H