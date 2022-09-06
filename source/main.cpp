#include <QtWidgets/QApplication>
#include "login/loginWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget lg;
    lg.show();
    return a.exec();
}   