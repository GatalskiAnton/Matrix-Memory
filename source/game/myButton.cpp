#include "myButton.h"

MyButton::MyButton(QWidget* parent, int value): QPushButton(parent), value(value)
{
    currentColor = value == 0 ? new QColor(77, 101, 129) : 
        value == 1 ? new QColor(48, 208, 112) : nullptr;

    timer = new QTimer(this);
    timer->start(5000);

    setEnabled(false);

    connect(timer, SIGNAL(timeout()), this, SLOT(resetColor()));
}

int MyButton::getValue() const
{
    return value;
}

void MyButton::setValue(int value)
{
    this->value = value;
}

void MyButton::setColor(const QColor* color)
{
    currentColor = new QColor(*color);
}

void MyButton::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setBrush(*currentColor);
    painter.setPen(QColor(109, 130, 148));
    painter.drawRect(0, 0, width(), width());
}

void MyButton::resetColor()
{
    currentColor = new QColor(77, 101, 129);

    timer->stop();

    setEnabled(true);
    update();
}