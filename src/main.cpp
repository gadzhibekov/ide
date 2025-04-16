#include "main_window.h"

#include <QApplication>

#include <iostream>

int main(int argc, char** argv)
{
    // std::cout << "1\n";/

    QApplication app(argc, argv);

    MainWindow main_window(nullptr);
    main_window.show();

    return app.exec();
}