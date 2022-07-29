#include "myButton.h"

MyButton::MyButton() : value_(0) {}

void MyButton::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	QBrush greenBrush(Qt::green);
	QBrush blackBrush(Qt::black);
	painter.setPen(QPen(Qt::black,5));
	if(value_ == 1)
	{
		painter.setBrush(greenBrush);
	}
	if(value_ == 0)
	{
		painter.setBrush(blackBrush);
	}
	painter.drawRect(0, 0, width(), width());
}