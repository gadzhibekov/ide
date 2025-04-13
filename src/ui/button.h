#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QString>

#include <functional>

struct Button : QPushButton
{
    Button(QWidget* parent);
    Button(QWidget* parent, std::function<void ()> slot);
    ~Button() = default;

    void                        set_icon(const QString& path);
    void                        set_text(const QString& text);
    void                        set_geometry(int x, int y, int w, int h);

private:
    std::function<void ()>      slot;
    void                        click();
};

#endif // BUTTON_H