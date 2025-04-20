#include "redactor.h"

Redactor::Redactor(QWidget* parent, int width, int height) : Widget(parent)
{
    this->set_geometry(300, 0, width - 300, height);
}

void Redactor::add_item(RedactorItem* item)
{
    items.push_back(item);
    item->show();
}