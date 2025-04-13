#include "button.h"

#include <QObject>

Button::Button(QWidget* parent) : QPushButton(parent)
{

}

Button::Button(QWidget* parent, std::function<void()> slot) : QPushButton(parent), slot(slot)
{
    QObject::connect(this, &Button::clicked, this, &Button::click);
}

void Button::set_icon(const QString& path)
{
    ;
}

void Button::set_text(const QString& text)
{
    this->setText(text);
}

void Button::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}

void Button::enterEvent(QEvent *event)
{
    enter();
    QPushButton::enterEvent(event);
}

void Button::leaveEvent(QEvent *event)
{
    leave();
    QPushButton::leaveEvent(event);
}

void Button::set_enter_slot(std::function<void()> slot)
{
    slot_for_enter = slot;
    QObject::connect(this, &Button::clicked, this, &Button::enter);
}

void Button::set_leave_slot(std::function<void()> slot)
{
    slot_for_leave = slot;
    QObject::connect(this, &Button::clicked, this, &Button::leave);
}

void Button::click()
{
    slot();
}

void Button::enter()
{
    if (slot_for_enter) slot_for_enter();
}

void Button::leave()
{
    if (slot_for_leave) slot_for_leave();
}