#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Calculator calculator;
    calculator.show();

    return app.exec();
}