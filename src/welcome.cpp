#include "welcome.h"

#include "panel_tools.h"

#include <QObject>
#include <QUrl>

Welcome::Welcome(QWidget* parent, int width, int height) : QWidget(parent)
{
    this->setGeometry(300, 0, width - 300, height);

    welcome_text_1 = new Label(this);
    welcome_text_1->set_text_size(15);
    welcome_text_1->set_text("Нажмите на кнопку");

    open_dir_prototype = new Button(this);
    open_dir_prototype->set_icon(OPEN_DIRECTORY_ICON_PATH);

    welcome_text_2 = new Label(this);
    welcome_text_2->set_text_size(15);
    welcome_text_2->set_text("для того чтобы открыть директорию");

    translate_to_leki = new Button(this);
    translate_to_leki->set_text("l");

    translate_to_ru = new Button(this);
    translate_to_ru->set_text("r");

    translate_to_en = new Button(this);
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