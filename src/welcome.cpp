#include "welcome.h"

#include "panel_tools.h"
#include "translator.h"

#include <QObject>
#include <QUrl>
// #include <QProcess>
// #include <QApplication>

#include <iostream>

Welcome::Welcome(QWidget* parent, int width, int height) : QWidget(parent)
{
    this->setGeometry(300, 0, width - 300, height);

    welcome_text_1 = new Label(this);
    welcome_text_1->set_text_size(15);
    welcome_text_1->set_text(Translator::current_language_data_set[0]);

    open_dir_prototype = new Button(this);
    open_dir_prototype->set_icon(OPEN_DIRECTORY_ICON_PATH);

    welcome_text_2 = new Label(this);
    welcome_text_2->set_text_size(15);
    welcome_text_2->set_text(Translator::current_language_data_set[1]);

    translate_to_leki = new Button(this, [=](){translate_to_leki_slot();});
    translate_to_leki->set_text("l");

    translate_to_ru = new Button(this, [=](){translate_to_ru_slot();});
    translate_to_ru->set_text("r");

    translate_to_en = new Button(this, [=](){translate_to_en_slot();});
    translate_to_en->set_text("e");

    github_link = new Button(this);
    github_link->set_text("g");

    tg_link = new Button(this);
    tg_link->set_text("t");

    player = new Player(this, FLOWERS_ANIM_PATH);
    player->setStyleSheet("background-color: black;");
}

void Welcome::resizeEvent(QResizeEvent* event)
{
    welcome_text_1->set_geometry((this->width() / 2) - 556 / 2, 60, 190, 25);
    open_dir_prototype->set_geometry((this->width() / 2) - 556 / 2 + 190, 65, 20, 20);
    welcome_text_2->set_geometry((this->width() / 2) - 556 / 2 + 190 + 30, 60, 346, 25);

    translate_to_leki->set_geometry(5, this->height() - 25 - 5, 50, 25);
    translate_to_ru->set_geometry(5 + 50 + 5, this->height() - 25 - 5, 50, 25);
    translate_to_en->set_geometry(5 + 50 + 5 + 50 + 5, this->height() - 25 - 5, 50, 25);

    tg_link->set_geometry(this->width() - 5 - 25, this->height() - 25 - 5, 25, 25);
    github_link->set_geometry(this->width() - 5 - 25 - 25 - 5, this->height() - 25 - 5, 25, 25);

    player->setGeometry((this->width() / 2) - 600 / 2, (this->height() / 2) - 600 / 2, 600, 600);
}

void Welcome::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}

void Welcome::set_dialog_window_ptr(DialogWindow* dialog_window)
{
    this->dialog_window = dialog_window;
}

void Welcome::translate_to_leki_slot()
{
    Translator::current_language = "leki";

    dialog_window_fill(); 
}

void Welcome::translate_to_ru_slot()
{
    Translator::current_language = "ru";

    dialog_window_fill();
}

void Welcome::translate_to_en_slot()
{
    Translator::current_language = "en";

    dialog_window_fill();
}

void Welcome::dialog_window_fill()
{
    dialog_window->set_title_text(Translator::current_language_data_set[9]);
    dialog_window->set_title_text_size(12);
    dialog_window->set_data_text(Translator::current_language_data_set[10]);
    dialog_window->set_data_text_size(10);
    dialog_window->set_cancel_btn_text(Translator::current_language_data_set[11]);
    dialog_window->set_ok_btn_text(Translator::current_language_data_set[12]);
    dialog_window->set_slot([=] () {
        
        // QProcess::startDetached(QCoreApplication::applicationFilePath());
        // QApplication::quit();

        dialog_window->hide();
    });

    dialog_window->show();
}