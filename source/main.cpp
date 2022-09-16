#include <QtWidgets/QApplication>
#include "login/loginWidget.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    LoginWidget loginWidget;
    loginWidget.show();
    return application.exec();
}