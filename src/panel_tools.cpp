#include "panel_tools.h"

#include "explorer.h"
#include "translator.h"

#include <QCoreApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QString>

#include <iostream>
#include <vector>
#include <cstdlib>

PanelTools::PanelTools(QWidget* parent, MainWindow* main_window, Panel* panel, Welcome* welcome, int width) 
: QWidget(parent), parent(parent), main_window(main_window), panel(panel), welcome(welcome), width(width)
{
    this->setStyleSheet("background-color: black;");

    right_regulator = new Button(this, [&](){right_regulate_click();});
    right_regulator->set_icon(RIGHT_ICON_PATH);

    left_regulator = new Button(this, [&](){left_regulate_click();});
    left_regulator->set_icon(LEFT_ICON_PATH);

    remove_item = new Button(this, [&](){remove_item_click();});
    remove_item->set_icon(DELETE_ICON_PATH);
    remove_item->set_icon_size(20, 20);
    remove_item->set_enter_slot([=](){remove_item->set_icon(DELETE_ACTIVE_ICON_PATH);
                                      remove_item->set_icon_size(20, 20);});
    remove_item->set_leave_slot([=](){remove_item->set_icon(DELETE_ICON_PATH);
                                      remove_item->set_icon_size(20, 20);});

    refresh = new Button(this, [&](){refresh_click();});
    refresh->set_icon(REFERSH_ICON_PATH);

    open_dir = new Button(this, [&](){open_dir_click();});
    open_dir->set_icon(OPEN_DIRECTORY_ICON_PATH);
    open_dir->set_icon_size(18, 18);

    explorer_path = new Label(this);
    explorer_path->set_text(Translator::current_language_data_set[2]);
    explorer_path->set_text_color(255, 255, 255);

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
    if (!(QFile::exists(Explorer::explorer_current_file))) return;

    QString command = "rm -rf " + Explorer::explorer_current_file;

    dialog_window->set_title_text(Translator::current_language_data_set[6]);
    dialog_window->set_data_text(QFileInfo(Explorer::explorer_current_file).fileName());
    dialog_window->set_cancel_btn_text(Translator::current_language_data_set[7]);
    dialog_window->set_ok_btn_text(Translator::current_language_data_set[8]);
    dialog_window->set_locate(parent->width(), parent->height());
    dialog_window->set_slot([=] () {
        std::system(command.toStdString().c_str());
        dialog_window->hide();
    });

    dialog_window->show();
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
    if (Explorer::explorer_directory == "") return;

    std::vector<QString> items;

    Explorer::delete_directory(panel, this);
    Explorer::get_directory(Explorer::explorer_directory, items);
    Explorer::load_directory(panel, this, welcome, items);
}

void PanelTools::set_dialog_window_ptr(DialogWindow* dialog_window)
{
    this->dialog_window = dialog_window;
}