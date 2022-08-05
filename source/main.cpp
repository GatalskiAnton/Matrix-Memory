#include "MatrixMemory.h"
#include "loginWidget.h"
#include <QtWidgets/QApplication>
#include "game/gameField.h"
#include "mainMenu.h"
#include "game/myButton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget lg;
    lg.show();
    return a.exec();
}
