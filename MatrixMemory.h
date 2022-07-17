#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MatrixMemory.h"

class MatrixMemory : public QMainWindow
{
    Q_OBJECT

public:
    MatrixMemory(QWidget *parent = nullptr);
    ~MatrixMemory();

private:
    Ui::MatrixMemoryClass ui;
};
