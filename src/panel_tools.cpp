#include "panel_tools.h"

#include "explorer.h"
#include "translator.h"
#include "../styles/styles.h"

#include <QCoreApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QString>

#include <iostream>
#include <vector>
#include <cstdlib>

PanelTools::PanelTools(QWidget* parent, MainWindow* main_window, Panel* panel, Welcome* welcome, int width) 
: Widget(parent), parent(parent), main_window(main_window), panel(panel), welcome(welcome), width(width)
{
    this->set_style(PANEL_TOOLS_STYLE_PATH);

    right_regulator = new Button(this, [&](){right_regulate_click();});
    right_regulator->set_icon(RIGHT_ICON_PATH);
    right_regulator->set_style(PANEL_TOOLS_BUTTON_STYLE_PATH);

    left_regulator = new Button(this, [&](){left_regulate_click();});
    left_regulator->set_icon(LEFT_ICON_PATH);
    left_regulator->set_style(PANEL_TOOLS_BUTTON_STYLE_PATH);

    remove_item = new Button(this, [&](){remove_item_click();});
    remove_item->set_icon(DELETE_ICON_PATH);
    remove_item->set_icon_size(20, 20);
    remove_item->set_enter_slot([=](){remove_item->set_icon(DELETE_ACTIVE_ICON_PATH);
                                      remove_item->set_icon_size(20, 20);});
    remove_item->set_leave_slot([=](){remove_item->set_icon(DELETE_ICON_PATH);
                                      remove_item->set_icon_size(20, 20);});
    remove_item->set_style(PANEL_TOOLS_BUTTON_STYLE_PATH);

    refresh = new Button(this, [&](){refresh_click();});
    refresh->set_icon(REFERSH_ICON_PATH);
    refresh->set_style(PANEL_TOOLS_BUTTON_STYLE_PATH);

    open_dir = new Button(this, [&](){open_dir_click();});
    open_dir->set_icon(OPEN_DIRECTORY_ICON_PATH);
    open_dir->set_icon_size(18, 18);
    open_dir->set_style(PANEL_TOOLS_BUTTON_STYLE_PATH);

    explorer_path = new Label(this);
    explorer_path->set_text(Translator::current_language_data_set[2]);
    explorer_path->set_text_color(255, 255, 255);
    explorer_path->set_style(PANEL_TOOLS_LABEL_STYLE_PATH);

    regulate_panels(width);
}

void PanelTools::set_geometry(int x, int y, int w, int h)
{
    regulate_panels(w);

    width = w;
}

void PanelTools::set_explorer_path(const QString& path)
{
    explorer_path->set_text(Translator::current_language_data_set[2] + path);
}

void PanelTools::left_regulate_click()
{
    if (width <= MINIMUM_PANEL_SIZE) return;

    width -= REGULATE_PANEL_SPEED;

    regulate_panels(width);
}

void PanelTools::right_regulate_click()
{
    if (width >= MAXIMUM_PANEL_SIZE) return;

    width += REGULATE_PANEL_SPEED;

    regulate_panels(width);
}

void PanelTools::regulate_panels(int width)
{
    this->setGeometry(0, 0, width, 20);

    right_regulator->set_geometry(width - 20, 0, 20, 20);
    left_regulator->set_geometry(width - 40, 0, 20, 20);
    remove_item->set_geometry(width - 60, 0, 20, 20);
    refresh->set_geometry(width - 80, 0, 20, 20);
    open_dir->set_geometry(width - 100, 0, 20, 20);
    explorer_path->set_geometry(0, 0, width - 100, 20);

    panel->set_geometry(0, 20, width, panel->height);
    welcome->set_geometry(panel->width, 0, main_window->width() - panel->width, main_window->height());
}

void PanelTools::remove_item_click()
{
    std::cout << Explorer::explorer_current_file.toStdString() << std::endl;

    if (Explorer::explorer_current_file.isEmpty()) return;

    if (!(QFile::exists(Explorer::explorer_current_file)))
    {
        fill_already_deleted_message(Translator::current_language_data_set[20], Translator::current_language_data_set[21], Translator::current_language_data_set[22]
        , Translator::current_language_data_set[23], [=] () {

            refresh_click();
            dialog_window->hide_widget();
        });

        return;
    }

    fill_already_deleted_message(Translator::current_language_data_set[6], QFileInfo(Explorer::explorer_current_file).fileName(), Translator::current_language_data_set[7]
    , Translator::current_language_data_set[8], [=] () {

        QString command = "rm -rf " + Explorer::explorer_current_file;
        std::system(command.toStdString().c_str());

        dialog_window->hide_widget();
    });
}

void PanelTools::open_dir_click()
{
    QString directory_path = QFileDialog::getExistingDirectory(nullptr, Translator::current_language_data_set[13], QDir::homePath());

    if (!directory_path.isEmpty()) 
    {
        std::vector<QString> items;
        
        Explorer::delete_directory(panel, this);
        Explorer::explorer_directory = directory_path;
        Explorer::get_directory(directory_path, items);
        Explorer::load_directory(panel, this, welcome, items);
    }
}

void PanelTools::refresh_click()
{
    if (Explorer::explorer_directory.isEmpty()) return;

    std::vector<QString> items;

    Explorer::delete_directory(panel, this);
    Explorer::get_directory(Explorer::explorer_directory, items);
    Explorer::load_directory(panel, this, welcome, items);
}

void PanelTools::set_dialog_window_ptr(DialogWindow* dialog_window)
{
    this->dialog_window = dialog_window;
}

void PanelTools::fill_already_deleted_message(const QString& text_1, const QString& text_2, const QString& text_3, const QString& text_4, std::function<void()> slot)
{
    dialog_window->set_title_text(text_1);
    dialog_window->set_data_text(text_2);
    dialog_window->set_cancel_btn_text(text_3);
    dialog_window->set_ok_btn_text(text_4);
    dialog_window->set_locate(parent->width(), parent->height());
    dialog_window->set_slot(slot);
    dialog_window->show_widget();
}