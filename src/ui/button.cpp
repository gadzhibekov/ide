#include "button.h"

#include <QObject>
#include <QIcon>
#include <QSize>
#include <QPalette>
#include <QColor>

Button::Button(QWidget* parent) : QPushButton(parent)
{
    
}

Button::Button(QWidget* parent, std::function<void()> slot) : QPushButton(parent), slot_for_click(slot)
{
    QObject::connect(this, &Button::clicked, this, &Button::click);
}

void Button::set_icon(const QString& path)
{
    this->setIcon(QIcon(path));
    this->setIconSize(QSize(15, 15));
}

void Button::set_icon_size(int width, int height)
{
    this->setIconSize(QSize(width, height));
}

void Button::set_text(const QString& text)
{
    this->setText(text);
}

void Button::set_color(int red, int green, int blue)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Button, QColor(red, green, blue));
    this->setPalette(palette);
    this->update();
}

void Button::set_color(int red, int green, int blue, double alpha)
{
    this->setStyleSheet(QString("QPushButton { background-color: rgba(%1, %2, %3, %4); }")
                        .arg(red)
                        .arg(green)
                        .arg(blue)
                        .arg(static_cast<int>(alpha * 255)));
    this->update();
}

void Button::set_opacity(double opacity)
{
    QPalette palette        = this->palette();
    QColor current_color    = palette.color(QPalette::Button);
    
    this->setStyleSheet(QString("background-color: rgba(%1, %2, %3, %4);")
        .arg(current_color.red())
        .arg(current_color.green())
        .arg(current_color.blue())
        .arg(opacity * 255));
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
    if (slot_for_click) slot_for_click();
}

void Button::enter()
{
    if (slot_for_enter) slot_for_enter();
}

void Button::leave()
{
    if (slot_for_leave) slot_for_leave();
}