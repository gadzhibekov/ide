#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

struct Widget : QWidget
{
    Widget(QWidget* parent);

    void        set_style(const QString& css_file_path);
    QWidget*    get_parent()    const   { return this->parent; }

private:
    QWidget*    parent;
};

#endif // WIDGET_H