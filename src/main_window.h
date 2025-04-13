#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "panel.h"
#include "panel_tools.h"
#include "ui/dialog_window.h"

#include <QMainWindow>
#include <QWidget>
#include <QResizeEvent>

struct MainWindow : QMainWindow
{
    explicit MainWindow(QWidget* parent);
    ~MainWindow() = default;

protected:
    void resizeEvent(QResizeEvent* event)   override;

private:
    QWidget*        central_widget;
    DialogWindow*   dialog_window;
    Panel*          panel;
    PanelTools*     panel_tools;
};

#endif // MAIN_WINDOW_H