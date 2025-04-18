#include "welcome.h"

#include "panel_tools.h"
#include "translator.h"
#include "explorer.h"
#include "config.h"

#include <QObject>
#include <QUrl>
#include <QFileDialog>
#include <QDesktopServices>

Welcome::Welcome(QWidget* parent, int width, int height) : QWidget(parent), parent(parent)
{
    this->setGeometry(300, 0, width - 300, height);
    this->setStyleSheet("background-color: black;");

    welcome_text_1 = new Label(this);
    welcome_text_1->set_text_size(15);
    welcome_text_1->set_text(Translator::current_language_data_set[0]);
    welcome_text_1->set_text_color(255, 255, 255);

    open_dir_prototype = new Button(this, [=](){open_dir_prototype_slot();});
    open_dir_prototype->set_icon(OPEN_DIRECTORY_ICON_PATH);

    welcome_text_2 = new Label(this);
    welcome_text_2->set_text_size(15);
    welcome_text_2->set_text(Translator::current_language_data_set[1]);
    welcome_text_2->set_text_color(255, 255, 255);

    translate_to_leki = new Button(this, [=](){translate_to_leki_slot();});
    translate_to_leki->set_icon(LEKI_FLAG_PATH);
    translate_to_leki->set_icon_size(50, 25);

    translate_to_ru = new Button(this, [=](){translate_to_ru_slot();});
    translate_to_ru->set_icon(RU_FLAG_PATH);
    translate_to_ru->set_icon_size(78, 35);

    translate_to_en = new Button(this, [=](){translate_to_en_slot();});
    translate_to_en->set_icon(US_FLAG_PATH);
    translate_to_en->set_icon_size(78, 35);

    github_link = new Button(this, [=](){open_github_link_slot();});
    github_link->set_icon(GITHUB_ICON_PATH);
    github_link->set_icon_size(25, 25);

    tg_link = new Button(this, [=](){open_tg_link_slot();});
    tg_link->set_icon(TG_ICON_PATH);
    tg_link->set_icon_size(25, 25);

    player = new Player(this, FLOWERS_ANIM_PATH);
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

void Welcome::set_panel_tools_ptr(PanelTools* panel_tools)
{
    this->panel_tools = panel_tools;
}

void Welcome::set_panel_ptr(Panel* panel)
{
    this->panel = panel;
}

void Welcome::translate_to_leki_slot()
{
    Translator::current_language = LEKI;

    fill_change_language_message(Translator::current_language_data_set[15]);
}

void Welcome::translate_to_ru_slot()
{
    Translator::current_language = RU;

    fill_change_language_message(Translator::current_language_data_set[16]);
}

void Welcome::translate_to_en_slot()
{
    Translator::current_language = EN;

    fill_change_language_message(Translator::current_language_data_set[17]);
}

void Welcome::open_dir_prototype_slot()
{
    QString directory_path = QFileDialog::getExistingDirectory(nullptr, Translator::current_language_data_set[13], QDir::homePath());

    if (!directory_path.isEmpty()) 
    {
        std::vector<QString> items;
        
        Explorer::delete_directory(panel, panel_tools);
        Explorer::explorer_directory = directory_path;
        Explorer::get_directory(directory_path, items);
        Explorer::load_directory(panel, panel_tools, this, items);
    }
}

void Welcome::open_github_link_slot()
{
    QDesktopServices::openUrl(QUrl(GITHUB_LINK));
}

void Welcome::open_tg_link_slot()
{
    QDesktopServices::openUrl(QUrl(TG_LINK));
}

void Welcome::fill_change_language_message(const QString& current_language)
{
    dialog_window->set_title_text(Translator::current_language_data_set[19]);
    dialog_window->set_data_text(Translator::current_language_data_set[10] + current_language + Translator::current_language_data_set[18]);
    dialog_window->set_data_text_size(10);
    dialog_window->set_cancel_btn_text(Translator::current_language_data_set[14]);
    dialog_window->set_locate(parent->width(), parent->height());
    dialog_window->set_slot(nullptr);
    dialog_window->show_widget();
}