#include "dialog_window.h"

#include "../translator.h"

#include <iostream>

#include <QObject>

DialogWindow::DialogWindow(QWidget* parent, int width, int height) : QWidget(parent)
{
    this->setGeometry(width / 2 - 100, height / 2 - 150, 300, 200);
    this->setStyleSheet("background-color: grey;");

    title = new Label(this);
    title->set_geometry(20, 20, 260, 40);
    title->setAlignment(Qt::AlignCenter);
    title->set_text_size(15);

    data = new Label(this);
    data->set_geometry(10, 70, 280, 60);
    data->setAlignment(Qt::AlignCenter);
    data->set_text_size(12);

    cancel = new Button(this);
    cancel->set_geometry(0, 150, this->width() / 2, 50);
    cancel->set_text(Translator::current_language_data_set[7]);

    ok = new Button(this);
    ok->set_geometry(this->width() / 2, 150, this->width() / 2, 50);
    cancel->set_text(Translator::current_language_data_set[14]);

    QObject::connect(cancel, &Button::clicked, this, &DialogWindow::click_cancel);

    this->hide();
}

void DialogWindow::set_slot(std::function<void()> slot)
{
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
    data->set_text(text);
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
    this->hide();
}

void DialogWindow::set_title_text_size(int size)
{
    title->set_text_size(size);
}

void DialogWindow::set_data_text_size(int size)
{
    data->set_text_size(size);
}