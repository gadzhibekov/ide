#include "redactor_item.h"
#include "redactor.h"
#include "../styles/styles.h"

#include <QFontMetrics>
#include <QFont>
#include <QRect>

RedactorItem::RedactorItem(QWidget* parent, int redactor_width, int redactor_elements_size) : Widget(parent)
{
    index   = new Button(this);
    line    = new LineEdit(this);
    
    line->setAlignment(Qt::AlignVCenter);

    index->set_text_color(255, 255, 255);
    line->set_text_color(255, 255, 255);

    index->set_style(REDACTOR_BUTTON_STYLE_PATH);
    
    x = 0;
    y = redactor_elements_size * REDACTOR_ITEM_SIZE;
    w = redactor_width;
    h = REDACTOR_ITEM_SIZE;

    this->set_geometry(x, y, w * 1000, h);
    index->set_geometry(x, x, h, h);
    line->set_geometry(h, 0, (w - h) * 1000, h);

    this->hide();
}

void RedactorItem::set_index(unsigned int idx)
{
    index->set_text(QString::number(static_cast<int>(idx)));
}

void RedactorItem::set_line(const QString& line_data)
{
    line->set_text(line_data);
}

void RedactorItem::set_line_text_size(int size)
{
    line->set_text_size(size);
}

void RedactorItem::set_button_text_size(int size)
{
    index->set_text_size(size);
}

void RedactorItem::set_line_text_size_with_save(int size)
{
    if (size < 0)
    {
        if (line->font().pointSize() == REDACTOR_ITEM_MINIMUM_TEXT_SIZE)     return;
    }
    else if (size > 0)
    {
        if (line->font().pointSize() == REDACTOR_ITEM_MAXIMUM_TEXT_SIZE)     return;
    }

    Redactor::item_text_size = line->font().pointSize() + size;

    line->set_text_size(Redactor::item_text_size);
}

void RedactorItem::set_button_text_size_with_save(int size)
{    
    if (size < 0)
    {
        if (index->font().pointSize() == REDACTOR_ITEM_MINIMUM_TEXT_SIZE)    return;
    }
    else if (size > 0)
    {
        if (index->font().pointSize() == REDACTOR_ITEM_MAXIMUM_TEXT_SIZE)    return;
    }

    Redactor::item_text_size = index->font().pointSize() + size;

    index->set_text_size(Redactor::item_text_size);
}

void RedactorItem::scroll_up()
{
    y += REDACTOR_SROLL_SPEED;

    this->setGeometry(x, y, w, h);
}

void RedactorItem::scroll_down()
{
    y -= REDACTOR_SROLL_SPEED;

    this->setGeometry(x, y, w, h);
}


void RedactorItem::scroll_right()
{
    x += REDACTOR_SROLL_SPEED;

    this->setGeometry(x, y, w, h);
}

void RedactorItem::scroll_left()
{
    x -= REDACTOR_SROLL_SPEED;

    this->setGeometry(x, y, w, h);
}