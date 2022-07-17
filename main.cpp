#include "MatrixMemory.h"
#include <QtWidgets/QApplication>
#include "gameField.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixMemory w;
    GameField gf;
    gf.show();
    w.show();
    return a.exec();
}
