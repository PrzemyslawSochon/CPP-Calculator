#include "./gui/main-window.hpp"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QWidget *containerWidget = new QWidget;
    containerWidget->setAttribute(Qt::WA_StyledBackground, true);

    return a.exec();
}