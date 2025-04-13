#ifndef EXPLORER_H
#define EXPLORER_H

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
    static QString                      explorer_file;
};

#endif // EXPLORER_H