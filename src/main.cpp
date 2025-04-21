#include "main_window.h"
#include "utils/config.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWindow main_window(nullptr, Config::read());
    main_window.show();

    return app.exec();
}