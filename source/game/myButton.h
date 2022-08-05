#pragma once

#include <QPushButton>
#include <QTimer>
#include <QColor>
#include <QFile>
#include <QPainter>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget* parent = nullptr,int value = 0);
    ~MyButton() = default;
    void setValue(int value);
    int getValue();
    void setColor(const QColor& color);
protected:
    void paintEvent(QPaintEvent*);
private:
    int value;
    QTimer* timer;
    QColor* currentColor;
private slots:
    void TimerScore();
};