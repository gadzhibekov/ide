#include "line_edit.h"

#include <QFont>
#include <QPalette>
#include <QColor>

LineEdit::LineEdit(QWidget* parent) : QLineEdit(parent)
{
    ;
}

void LineEdit::set_text(const QString& text)
{
    setText(text);
}

void LineEdit::set_geometry(int x, int y, int w, int h)
{   
    setGeometry(x, y, w, h);
}

void LineEdit::set_text_size(int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    this->setFont(font);
}

void LineEdit::set_text_color(int red, int green, int blue)
{
    QPalette palette = this->palette();
    QColor custom_color(red, green, blue);
    palette.setColor(QPalette::Text, custom_color);
    this->setPalette(palette);
}