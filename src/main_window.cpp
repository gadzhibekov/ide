#include "main_window.h"

#include "panel_item.h"
#include "explorer.h"

#include <QString>

#include <vector>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    central_widget  = new QWidget(this);

    this->setCentralWidget(central_widget);
    this->setMinimumSize(1200, 800);
    this->setWindowTitle("ide");

    panel           = new Panel(central_widget, 600, this->height());
    panel_tools     = new PanelTools(central_widget, panel, 600);
    dialog_window   = new DialogWindow(central_widget, this->width(), this->height());

    panel_tools->set_dialog_window(dialog_window);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    panel->set_geometry(0, 20, panel->width, this->height());
    panel_tools->set_geometry(0, 20, panel_tools->width, 20);
}