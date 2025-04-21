#include "redactor.h"

#include <QKeyEvent>
#include <QDebug>

int Redactor::item_text_size = 12;

Redactor::Redactor(QWidget* parent, int width, int height) : Widget(parent)
{
    this->set_geometry(300, 0, width - 300, height);
}

void Redactor::wheelEvent(QWheelEvent* event)
{
    if (event->modifiers() & Qt::ControlModifier) 
    {
        
        if (event->angleDelta().y() > 0)    regulate_text_size(REGULATE_TEXT_SIZE);
        else                                regulate_text_size(-REGULATE_TEXT_SIZE);

        event->accept();
    }
    else if (event->modifiers() & Qt::ShiftModifier) 
    {
        for (auto item : items)
        {
            if (event->angleDelta().y() > 0)    item->scroll_right();
            else                                item->scroll_left();
        }
        
        QWidget::wheelEvent(event);
    }  
    else 
    {
        for (auto item : items)
        {
            if (event->angleDelta().y() > 0)    item->scroll_up();
            else                                item->scroll_down();
        }
        
        QWidget::wheelEvent(event);
    }
}

void Redactor::regulate_text_size(int size)
{
    for (int i = 0; i < items.size(); ++i)
    {
        items[i]->set_button_text_size_with_save(size);
        items[i]->set_line_text_size_with_save(size);
    }
}

void Redactor::add_item(RedactorItem* item)
{
    items.push_back(item);
    item->show();
}

void Redactor::remove_all()
{
    if (items.size() == 0) return;

    for (auto ptr : items)
    {
        if (!ptr) continue;
        
        delete ptr;
        ptr = nullptr;
    }

    items.clear();
}