#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

struct Widget : QWidget
{
    Widget(QWidget* parent);

    void                set_style(const QString& css_file_path);
    virtual void        set_geometry(int x, int y, int w, int h);

    QWidget*            get_parent()    const   { return this->parent; }

private:
    QWidget*            parent;
};

#endif // WIDGET_H