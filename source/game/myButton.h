#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QColor>
#include <QPainter>

class MyButton : public QPushButton
{
	Q_OBJECT
public:
	MyButton(QWidget* parent = nullptr, int value = 0);
	~MyButton() = default;
	int getValue() const;
	void setValue(int value);
	void setColor(const QColor* color);
protected:
	void paintEvent(QPaintEvent* event);
protected slots:
	void resetColor();
private:
	int value;
	QTimer* timer;
	QColor* currentColor;
};

#endif