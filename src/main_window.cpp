#include "main_window.h"

#include "panel_item.h"

#include <QString>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    central_widget = new QWidget(this);

    this->setCentralWidget(central_widget);
    this->setMinimumSize(1200, 800);
    this->setWindowTitle("ide");

    panel = new Panel(central_widget, this->width() / 3, this->height());

    for (int i = 0; i < 20; ++i)
    {
        PanelItem* panel_item = new PanelItem(panel, panel->width(), panel->elements_size());
        panel_item->set_icon("icon_" + QString::number(i + 1));
        panel_item->set_file("path_to_file_" + QString::number(i + 1));

        panel->add_item(panel_item);
    }

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    panel->set_geometry(0, 0, this->width() / 3, this->height());
}