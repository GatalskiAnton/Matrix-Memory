#pragma once

#include <QPushButton>
#include <QPainter>

class MyButton:public QPushButton
{
public:
	MyButton();
	int getValue() const { return value_; }
	void setValue(int value) { value_ = value; }
protected:
	void paintEvent(QPaintEvent*);
private:
	int value_;
};