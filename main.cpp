#include "widget.h"
#include "stdlib.h"
#include "startscreen.h"
#include "privatescreen.h"
#include "hafdisplay.h"
#include <QApplication>
#include <qdesktopwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //PrivateScreen w;
   // Widget w(0,12345);
    //HafDisplay w;
    StartScreen w;
    //system("pause");
    //Widget h(0,54321);
    //h.show();
    QDesktopWidget* desktopwight = QApplication::desktop();
    QRect screenRect = desktopwight->availableGeometry();

    w.move(screenRect.width()*2/3,0);
    w.show();

    return a.exec();
}
