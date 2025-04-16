#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#define MINIMUM_MAIN_WINDOW_WIDTH   1200
#define MINIMUM_MAIN_WINDOW_HEIGHT  800
#define MAIN_WINDOW_TITLE           "ide"

#include "panel.h"
#include "panel_tools.h"
#include "welcome.h"
#include "ui/dialog_window.h"

#include <QMainWindow>
#include <QWidget>
#include <QResizeEvent>

struct PanelTools;
struct Welcome;

struct MainWindow : QMainWindow
{
    explicit MainWindow(QWidget* parent);
    ~MainWindow();

protected:
    void            resizeEvent(QResizeEvent* event)   override;

private:
    QWidget*        central_widget;
    DialogWindow*   dialog_window;
    Panel*          panel;
    PanelTools*     panel_tools;
    Welcome*        welcome;
};

#endif // MAIN_WINDOW_H