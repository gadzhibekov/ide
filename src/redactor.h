#ifndef REDACTOR_H
#define REDACTOR_H

#include "ui/widget.h"
#include "redactor_item.h"

#include <QWidget>

#include <vector>

struct RedactorItem;

struct Redactor : Widget
{
    Redactor(QWidget* parent, int width, int height);

    void                            add_item(RedactorItem* item);
    std::vector<RedactorItem *>&    get_items_vector()  { return items; };

private:
    std::vector<RedactorItem *>     items;
};

#endif //REDACTOR_H