#include "GameWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.showFullScreen();

    return a.exec();
}
