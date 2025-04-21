#ifndef REDACTOR_H
#define REDACTOR_H

#define REGULATE_TEXT_SIZE 1

#include "ui/widget.h"
#include "redactor_item.h"

#include <QWidget>
#include <QWheelEvent>

#include <vector>

struct RedactorItem;

struct Redactor : Widget
{
    Redactor(QWidget* parent, int width, int height);

    void                            add_item(RedactorItem* item);
    void                            remove_all();
    void                            regulate_text_size(int size);
    static int                      item_text_size;

    std::vector<RedactorItem *>&    get_items_vector()              { return items; }

protected:
    void                            wheelEvent(QWheelEvent* event)                          override;

private:                
    std::vector<RedactorItem *>     items;
};

#endif //REDACTOR_H