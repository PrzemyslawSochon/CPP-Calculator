#include "./gui/main-window.hpp"
#include "./gui/config-utilities.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    loadConfigFile();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QWidget *containerWidget = new QWidget;
    containerWidget->setAttribute(Qt::WA_StyledBackground, true);

    return a.exec();
}