#include "label.h"

#include <QFont>

Label::Label(QWidget* parent) : QLabel(parent)
{
    
}

void Label::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}

void Label::set_text_size(int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    this->setFont(font);
}