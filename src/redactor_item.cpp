#include "redactor_item.h"

RedactorItem::RedactorItem(QWidget* parent, int redactor_width, int redactor_elements_size) : Widget(parent)
{
    index   = new Button(this);
    line    = new LineEdit(this);
    
    line->setAlignment(Qt::AlignVCenter);

    index->set_text_color(255, 255, 255);
    line->set_text_color(255, 255, 255);

    // index->set_style(PANEL_TOOLS_ITEM_LABEL_STYLE_PATH);
    // line->set_style(PANEL_TOOLS_ITEM_LABEL_STYLE_PATH);
    
    x = 0;
    y = redactor_elements_size * REDACTOR_ITEM_SIZE;
    w = redactor_width;
    h = REDACTOR_ITEM_SIZE;

    this->set_geometry(x, y, w * 1000, h);
    index->set_geometry(x, x, h, h);
    line->set_geometry(h, 0, (w - h) * 1000, h);

    // this->set_style(PANEL_TOOLS_ITEM_STYLE_PATH);
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