#include "panel_tools.h"

#include "explorer.h"

#include <iostream>

#include <QCoreApplication>
#include <QFileDialog>
#include <QString>

#include <vector>

PanelTools::PanelTools(QWidget* parent, Panel* panel, int width) : QWidget(parent), panel(panel), width(width)
{
    this->setStyleSheet("background-color: grey;");

    right_regulator = new Button(this, [&](){right_regulate_click();});
    right_regulator->set_text(">");

    left_regulator = new Button(this, [&](){left_regulate_click();});
    left_regulator->set_text("<");

    remove_item = new Button(this, [&](){remove_item_click();});
    remove_item->set_text("r");

    refresh = new Button(this, [&](){refresh_click();});
    refresh->set_text("u");

    open_dir = new Button(this, [&](){open_dir_click();});
    open_dir->set_text("o");

    explorer_path = new Label(this);
    explorer_path->set_text("Explorer");

    regulate_panels(width);
}

void PanelTools::set_geometry(int x, int y, int w, int h)
{
    regulate_panels(w);

    width = w;
}

void PanelTools::set_explorer_path(const QString& path)
{
    explorer_path->set_text((QString)"EXPLORER: " + path);
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
}

void PanelTools::remove_item_click()
{
    std::cout << "remove\n";
}

void PanelTools::open_dir_click()
{
    QString directory_path = QFileDialog::getExistingDirectory(nullptr, "Выберите директорию", QDir::homePath());

    if (!directory_path.isEmpty()) 
    {
        std::vector<QString> items;
        
        Explorer::delete_directory(panel, this);
        Explorer::explorer_directory = directory_path;
        Explorer::get_directory(directory_path, items);
        Explorer::load_directory(panel, this, items);
    }
}

void PanelTools::refresh_click()
{
    if (Explorer::explorer_directory == "") return;

    std::vector<QString> items;

    Explorer::delete_directory(panel, this);
    Explorer::get_directory(Explorer::explorer_directory, items);
    Explorer::load_directory(panel, this, items);
}