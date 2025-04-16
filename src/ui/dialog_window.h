#ifndef DIALOG_WINDOW_H
#define DIALOG_WINDOW_H

#include "button.h"
#include "label.h"

#include <QWidget>

#include <functional>

struct DialogWindow : QWidget
{
    DialogWindow(QWidget* parent, int width, int height);

    void                        set_slot(std::function<void()> slot);
    void                        set_title_text(const QString& text);
    void                        set_title_text_size(int size);
    void                        set_data_text(const QString& text);
    void                        set_data_text_size(int size);
    void                        set_ok_btn_text(const QString& text);
    void                        set_cancel_btn_text(const QString& text);
    void                        set_locate(int x, int y);

private:
    Label*                      title;
    Label*                      data;
    Button*                     ok;
    Button*                     cancel;

    std::function<void()>       slot;
    void                        click_ok();
    void                        click_cancel();
};

#endif // DIALOG_WINDOW_H