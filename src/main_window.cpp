#include "main_window.h"

#include "panel_item.h"
#include "explorer.h"
#include "config.h"
#include "translator.h"

#include <QString>
#include <QDebug>

#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    ConfigData config_data = Config::read();

    Translator translator(config_data.language);

    central_widget  = new QWidget(this);

    this->setStyleSheet("background-color: black;");
    this->setCentralWidget(central_widget);
    this->setMinimumSize(MINIMUM_MAIN_WINDOW_WIDTH, MINIMUM_MAIN_WINDOW_HEIGHT);
    this->setWindowTitle(MAIN_WINDOW_TITLE);

    welcome         = new Welcome(central_widget, this->width(), this->height());
    panel           = new Panel(central_widget, MINIMUM_MAIN_WINDOW_WIDTH / 4, this->height());
    panel_tools     = new PanelTools(central_widget, this, panel, welcome, this->width() / 4);
    dialog_window   = new DialogWindow(central_widget, this->width(), this->height());

    panel_tools->set_dialog_window_ptr(dialog_window);
    welcome->set_dialog_window_ptr(dialog_window);
    welcome->set_panel_tools_ptr(panel_tools);
    welcome->set_panel_ptr(panel);

    if (!config_data.last_project_dir.isEmpty())
    {
        dialog_window->set_title_text(Translator::current_language_data_set[3]);

        if (config_data.language == "leki")         dialog_window->set_title_text_size(10);
        else                                        dialog_window->set_title_text_size(12);

        dialog_window->set_data_text(config_data.last_project_dir);
        dialog_window->set_data_text_size(10);
        dialog_window->set_cancel_btn_text(Translator::current_language_data_set[4]);
        dialog_window->set_ok_btn_text(Translator::current_language_data_set[5]);
        dialog_window->set_slot([=] () {

            std::vector<QString> items;

            Explorer::delete_directory(panel, panel_tools);
            Explorer::explorer_directory = config_data.last_project_dir;
            Explorer::get_directory(config_data.last_project_dir, items);
            Explorer::load_directory(panel, panel_tools, welcome, items);

            dialog_window->hide();
        });

        dialog_window->show();
    }
}

MainWindow::~MainWindow()
{
    Config::write(ConfigData({Explorer::explorer_directory, Translator::current_language}));
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    panel->set_geometry(0, 20, panel->width, this->height());
    panel_tools->set_geometry(0, 0, panel_tools->width, 20);
    welcome->set_geometry(panel->width, 0, this->width() - panel->width, this->height());
}