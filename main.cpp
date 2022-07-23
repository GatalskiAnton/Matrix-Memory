#include "MatrixMemory.h"
#include <QtWidgets/QApplication>
#include "gameField.h"
#include "mainMenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu startMenu;
    startMenu.setFixedSize(750, 900);
    startMenu.show();
    
    return a.exec();
}
