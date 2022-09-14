/********************************************************************************
** Form generated from reading UI file 'MatrixMemory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXMEMORY_H
#define UI_MATRIXMEMORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatrixMemoryClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MatrixMemoryClass)
    {
        if (MatrixMemoryClass->objectName().isEmpty())
            MatrixMemoryClass->setObjectName(QString::fromUtf8("MatrixMemoryClass"));
        MatrixMemoryClass->resize(600, 400);
        menuBar = new QMenuBar(MatrixMemoryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MatrixMemoryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MatrixMemoryClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MatrixMemoryClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MatrixMemoryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MatrixMemoryClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MatrixMemoryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MatrixMemoryClass->setStatusBar(statusBar);

        retranslateUi(MatrixMemoryClass);

        QMetaObject::connectSlotsByName(MatrixMemoryClass);
    } // setupUi

    void retranslateUi(QMainWindow *MatrixMemoryClass)
    {
        MatrixMemoryClass->setWindowTitle(QCoreApplication::translate("MatrixMemoryClass", "MatrixMemory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatrixMemoryClass: public Ui_MatrixMemoryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXMEMORY_H
