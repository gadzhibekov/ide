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

void Button::click()
{
    slot();
}