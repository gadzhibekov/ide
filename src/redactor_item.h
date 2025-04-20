#ifndef REDACTOR_ITEM_H
#define REDACTOR_ITEM_H

#define REDACTOR_ITEM_SIZE 30

#include "ui/widget.h"
#include "ui/button.h"
#include "ui/label.h"
#include "ui/line_edit.h"

#include <QWidget>
#include <QString>

struct RedactorItem : Widget
{
    RedactorItem(QWidget* parent, int redactor_width, int redactor_elements_size);

    void        set_index(unsigned int idx);
    void        set_line(const QString& line_data);

    int         x;
    int         y;
    int         w;
    int         h;

private:
    Button*     index;
    LineEdit*   line;  
};

#endif // REDACTOR_ITEM_H