#include "MatrixMemory.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixMemory w;
    w.show();
    return a.exec();
}
