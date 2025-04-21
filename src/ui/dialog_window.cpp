#include "dialog_window.h"
#include "../utils/translator.h"
#include "../../styles/styles.h"

#include <QObject>

#include <string>

DialogWindow::DialogWindow(QWidget* parent, int width, int height) : Widget(parent)
{
    this->setGeometry(width / 2 - DIALOG_WINDOW_MINIMUM_WIDTH / 2, height / 2 - DIALOG_WINDOW_MINIMUM_HEIGHT / 2, DIALOG_WINDOW_MINIMUM_WIDTH, DIALOG_WINDOW_MINIMUM_HEIGHT);
    this->set_style(DIALOG_WINDOW_STYLE_PATH);

    title = new Label(this);
    title->set_geometry(20, 20, 260, 40);
    title->setAlignment(Qt::AlignCenter);
    title->set_text_size(15);

    data = new Label(this);
    data->set_geometry(10, 70, 280, 60);
    data->setAlignment(Qt::AlignCenter);
    data->set_text_size(12);

    ok = new Button(this);
    ok->set_geometry(this->width() / 2, DIALOG_WINDOW_MINIMUM_HEIGHT, this->width() / 2, 50);
    ok->set_style(DIALOG_WINDOW_BUTTON_RIGHT_STYLE_PATH);

    cancel = new Button(this);
    cancel->set_geometry(0, DIALOG_WINDOW_MINIMUM_HEIGHT, this->width() / 2, 50);
    cancel->set_text(Translator::current_language_data_set[7]);
    cancel->set_text(Translator::current_language_data_set[14]);
    cancel->set_style(DIALOG_WINDOW_BUTTON_LEFT_STYLE_PATH);

    QObject::connect(cancel, &Button::clicked, this, &DialogWindow::click_cancel);

    this->hide();
}

void DialogWindow::set_slot(std::function<void()> slot)
{
    if (slot)
    {
        ok->set_style(DIALOG_WINDOW_BUTTON_RIGHT_STYLE_PATH);
        cancel->set_style(DIALOG_WINDOW_BUTTON_LEFT_STYLE_PATH);
    }
    else
    {
        ok->set_style(DIALOG_WINDOW_BUTTON_COMMON_STYLE_PATH);
        cancel->set_style(DIALOG_WINDOW_BUTTON_COMMON_STYLE_PATH);
    }

    this->slot = slot;
    QObject::connect(ok, &Button::clicked, this, &DialogWindow::click_ok);
}

void DialogWindow::click_ok()
{
    slot();
}

void DialogWindow::set_title_text(const QString& text)
{
    title->set_text(text);
}

void DialogWindow::set_data_text(const QString& text)
{
    this->setGeometry(this->pos().x(), this->pos().y(), DIALOG_WINDOW_MINIMUM_WIDTH, DIALOG_WINDOW_MINIMUM_HEIGHT);
    ok->set_geometry(this->width() / 2, DIALOG_WINDOW_MINIMUM_HEIGHT, this->width() / 2, 50);
    cancel->set_geometry(0, DIALOG_WINDOW_MINIMUM_HEIGHT, this->width() / 2, 50);
    data->set_geometry(10, 70, 280, 60);

    std::string std_text        = text.toStdString();
    std::string res_std_text    = "";
    int p                       = 0;

    for (int i = 0, j = 0; i < std_text.size(); ++i)
    {
        if (std_text[i] == '\n')
        {
            j = 0;
            p++;
        }
        else
        {
            j++;
        }

        res_std_text += std_text[i];

        if (j == 35)
        {
            res_std_text += '\n';
            j = 0; 
            p++;
        }
    }

    if (p > 2)
    {
        int _p = p - 2;
        int _h = _p * 20;

        this->set_geometry(this->pos().x(), this->pos().y(), this->width(), this->height() + _h);
        data->set_geometry(10, 70, 280, data->height() + _h);

        cancel->set_geometry(0, data->pos().y() + data->height() + 20, this->width() / 2, 50);
        ok->set_geometry(this->width() / 2, data->pos().y() + data->height() + 20, this->width() / 2, 50);
    }

    data->set_text(QString::fromStdString(res_std_text));
}

void DialogWindow::set_ok_btn_text(const QString& text)
{
    ok->set_text(text);
}

void DialogWindow::set_cancel_btn_text(const QString& text)
{
    cancel->set_text(text);
}

void DialogWindow::click_cancel()
{
    hide_widget();
}

void DialogWindow::set_title_text_size(int size)
{
    title->set_text_size(size);
}

void DialogWindow::set_data_text_size(int size)
{
    data->set_text_size(size);
}

void DialogWindow::set_locate(int x, int y)
{
    setGeometry(x / 2 - this->width() / 2, y / 2 - this->height() / 2, this->width(), this->height());
}

void DialogWindow::show_widget()
{
    if (slot)
    {
        cancel->set_geometry(0, data->pos().y() + data->height() + 20, this->width() / 2, 50);
        ok->set_geometry(this->width() / 2, data->pos().y() + data->height() + 20, this->width() / 2, 50);
    }
    else
    {
        cancel->set_geometry(0, data->pos().y() + data->height() + 20, this->width(), 50);
        ok->set_geometry(this->width() / 2, data->pos().y() + data->height() + 20, 0, 0);
    }

    show();
}

void DialogWindow::hide_widget()
{
    hide();
}