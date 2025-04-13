#include "label.h"

Label::Label(QWidget* parent) : QLabel(parent)
{
    
}

void Label::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}