#ifndef PANEL_TOOLS_H
#define PANEL_TOOLS_H

#define OPEN_DIRECTORY_ICON_PATH    "../res/folder.png"
#define REFERSH_ICON_PATH           "../res/refresh.png"
#define DELETE_ICON_PATH            "../res/delete.png"
#define DELETE_ACTIVE_ICON_PATH     "../res/delete_active.png"
#define LEFT_ICON_PATH              "../res/left.png"
#define RIGHT_ICON_PATH             "../res/right.png"

#define MINIMUM_PANEL_SIZE          100
#define MAXIMUM_PANEL_SIZE          1200
#define REGULATE_PANEL_SPEED        100

#include "ui/button.h"
#include "ui/label.h"
#include "ui/dialog_window.h"
#include "ui/widget.h"
#include "main_window.h"
#include "panel.h"
#include "welcome.h"

#include <QWidget>
#include <QString>

#include <functional>

struct MainWindow;
struct Welcome;
struct Redactor;

struct PanelTools : Widget
{
    PanelTools(QWidget* parent, MainWindow* main_window, Panel* panel, Welcome* welcome, Redactor* redactor, int width);
    
    void                set_geometry(int x, int y, int w, int h) override;
    void                set_explorer_path(const QString& path);
    void                set_dialog_window_ptr(DialogWindow* dialog_window);

    int                 width;

private:
    QWidget*            parent;
    Panel*              panel;
    Label*              explorer_path;
    Button*             open_dir;
    Button*             refresh;
    Button*             remove_item;
    Button*             left_regulator;
    Button*             right_regulator;
    DialogWindow*       dialog_window;
    MainWindow*         main_window;
    Welcome*            welcome;
    Redactor*           redactor;

    void                open_dir_click();
    void                refresh_click();
    void                remove_item_click();
    void                left_regulate_click();
    void                right_regulate_click();

    void                regulate_panels(int width);
    void                fill_already_deleted_message(const QString& text_1, const QString& text_2, const QString& text_3, const QString& text_4, std::function<void()> slot);
};

#endif // PANEL_TOOLS_H