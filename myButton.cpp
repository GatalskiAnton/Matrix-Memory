#include "myButton.h"


MyButton::MyButton(int value, QWidget* parent)
    : QPushButton(parent), value_(value)
{
    if (value == 0)
    {
        color = QColor(77,101,129);
    }
    if (value == 1)
    {
        color = QColor(48,208,112);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerScore()));
    
    this->setEnabled(false);
    isFirstRepaint = true;

    QFile file("styles/buttonStyle.qss");
    file.open(QFile::ReadOnly);
    setStyleSheet(file.readAll());
}

void MyButton::setColor(QColor color)
{
    this->color = color;
}

void MyButton::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
    painter.setBrush(color);
    painter.setPen(QColor(109,130,148));
	painter.drawRect(0, 0, width(), width());
    if (isVisible() && isFirstRepaint)
    {
        timer->start(5000);
    }
    isFirstRepaint = false;
}

void MyButton::TimerScore()
{
    color = QColor(77, 101, 129);
    this->setEnabled(true);
    timer->stop();
    update();
}

void MyButton::setValue(int value)
{
    value_ = value;
}

int MyButton::getValue()
{
    return value_;
}