#include "mainwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("f8industries");
    QApplication::setApplicationName("myGCS");
    QApplication::setApplicationVersion("0.1");

    mainWidget w;
    //w.showFullScreen();
    //w.show();
    w.showMaximized();

    return a.exec();
}
