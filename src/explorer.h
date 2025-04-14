#ifndef EXPLORER_H
#define EXPLORER_H

#define CPP_ICON_PATH           "../res/cpp.png"
#define C_ICON_PATH             "../res/c.png"
#define HEADER_ICON_PATH        "../res/header.png"
#define CMAKE_ICON_PATH         "../res/cmake.png"
#define GITIGNORE_ICON_PATH     "../res/git.png"

#include "panel.h"
#include "panel_item.h"
#include "panel_tools.h"

#include <QString>

#include <vector>

struct Explorer
{
    static void                         load_directory(Panel* panel, PanelTools* panel_tools, std::vector<QString> dir_vector);
    static void                         delete_directory(Panel* panel, PanelTools* panel_tools);
    static void                         get_directory(QString directory, std::vector<QString>& dir_vector);

    static QString                      explorer_directory;
    static QString                      explorer_current_file;
    static QString                      explorer_current_file_data;
};

#endif // EXPLORER_H