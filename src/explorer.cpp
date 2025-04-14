#include "explorer.h"

#include <QDir>
#include <QStringList>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

QString Explorer::explorer_directory            = "";
QString Explorer::explorer_current_file         = "";
QString Explorer::explorer_current_file_data    = "";

void Explorer::get_directory(QString directory, std::vector<QString>& dir_vector)
{
    QDir dir(directory);

    if (!dir.exists())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Указанная директория (" + directory + ") не существует");
        return;
    }
    
    QStringList entries = dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for (const QString& entry : entries) 
    {
        QString full_path = dir.filePath(entry);
        
        if (QDir(full_path).exists())
        {
            get_directory(full_path, dir_vector);
        } 
        else 
        {
            dir_vector.push_back(full_path);
        }
    }
}

void Explorer::load_directory(Panel* panel, PanelTools* panel_tools, std::vector<QString> dir_vector)
{
    for (auto file : dir_vector)
    {
        QString extension = QFileInfo(file).suffix().toLower();

        if (!(extension == "cpp" || extension == "hpp" || extension == "c" || extension == "h" ||
            extension == "gitignore" || QFileInfo(file).fileName() == "CMakeLists.txt")) continue;

        PanelItem* panel_item = new PanelItem(panel, 600, panel->elements_size());

        panel_item->set_file(file);
        panel_item->get_file()->set_text_size(13);

        if (extension == "cpp")                                 panel_item->get_icon()->set_icon(CPP_ICON_PATH);
        if (extension == "c")                                   panel_item->get_icon()->set_icon(C_ICON_PATH);
        if (extension == "h")                                   panel_item->get_icon()->set_icon(HEADER_ICON_PATH);
        if (extension == "hpp")                                 panel_item->get_icon()->set_icon(HEADER_ICON_PATH);
        if (extension == "gitignore")                           panel_item->get_icon()->set_icon(GITIGNORE_ICON_PATH);
        if (QFileInfo(file).fileName() == "CMakeLists.txt")     panel_item->get_icon()->set_icon(CMAKE_ICON_PATH);

        panel_item->get_icon()->set_icon_size(40);
        panel->add_item(panel_item);
    }

    panel_tools->set_explorer_path(Explorer::explorer_directory);
}

void Explorer::delete_directory(Panel* panel, PanelTools* panel_tools)
{
    panel_tools->set_explorer_path("");

    panel->remove_all();
}