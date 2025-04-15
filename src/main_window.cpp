#include "main_window.h"

#include "panel_item.h"
#include "explorer.h"

#include <QString>

#include <vector>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    central_widget  = new QWidget(this);

    this->setCentralWidget(central_widget);
    this->setMinimumSize(MINIMUM_MAIN_WINDOW_WIDTH, MINIMUM_MAIN_WINDOW_HEIGHT);
    this->setWindowTitle(MAIN_WINDOW_TITLE);

    welcome         = new Welcome(central_widget, this->width(), this->height());
    panel           = new Panel(central_widget, MINIMUM_MAIN_WINDOW_WIDTH / 4, this->height());
    panel_tools     = new PanelTools(central_widget, this, panel, welcome, this->width() / 4);
    dialog_window   = new DialogWindow(central_widget, this->width(), this->height());

    panel_tools->set_dialog_window_ptr(dialog_window);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    panel->set_geometry(0, 20, panel->width, this->height());
    panel_tools->set_geometry(0, 0, panel_tools->width, 20);
    welcome->set_geometry(panel->width, 0, this->width() - panel->width, this->height());
}