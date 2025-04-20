#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <QLineEdit>
#include <QWidget>
#include <QString>

struct LineEdit : QLineEdit
{
    LineEdit(QWidget* parent);

    void    set_text(const QString& text);
    void    set_text_size(int size);
    void    set_geometry(int x, int y, int w, int h);
    void    set_text_color(int red, int green, int blue);
};

#endif // LINE_EDIT_H