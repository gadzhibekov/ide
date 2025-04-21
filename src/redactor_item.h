#ifndef REDACTOR_ITEM_H
#define REDACTOR_ITEM_H

#define REDACTOR_SROLL_SPEED            40
#define REDACTOR_ITEM_SIZE              30
#define REDACTOR_ITEM_MINIMUM_TEXT_SIZE 10
#define REDACTOR_ITEM_MAXIMUM_TEXT_SIZE 18

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
    void        set_line_text_size(int size);
    void        set_button_text_size(int size);      
    void        set_line_text_size_with_save(int size);
    void        set_button_text_size_with_save(int size);

    void        scroll_up();
    void        scroll_down();
    void        scroll_right();
    void        scroll_left();

    int         x;
    int         y;
    int         w;
    int         h;

private:
    Button*     index;
    LineEdit*   line;  
};

#endif // REDACTOR_ITEM_H