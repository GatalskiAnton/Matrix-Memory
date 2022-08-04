#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QColor>
#include <QFile>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton(int value, QWidget* parent = nullptr);
    ~MyButton() = default;
    void setValue(int value);
    int getValue();
    void setColor(QColor color);
protected:
    void paintEvent(QPaintEvent*);
private:
    QTimer* timer;
    int value_;
    QColor color;
    bool isFirstRepaint;
private slots:
    void TimerScore();
};