#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QEvent>

#include <functional>

struct Button : QPushButton
{
    Button(QWidget* parent);
    Button(QWidget* parent, std::function<void()> slot);
    ~Button() = default;

    void                        set_icon(const QString& path);
    void                        set_text(const QString& text);
    void                        set_geometry(int x, int y, int w, int h);
    void                        set_enter_slot(std::function<void()> slot);
    void                        set_leave_slot(std::function<void()> slot);

protected:
    void                        enterEvent(QEvent* event) override;
    void                        leaveEvent(QEvent* event) override;

private:
    std::function<void ()>      slot;
    std::function<void ()>      slot_for_enter;
    std::function<void ()>      slot_for_leave;

    void                        click();
    void                        enter();
    void                        leave();
};

#endif // BUTTON_H