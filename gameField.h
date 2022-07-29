#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "myButton.h"
#include <QVector>
#include <QGridLayout>

class GameField: public QWidget
{
	Q_OBJECT
public:
	explicit GameField(QWidget* parent = nullptr);
	~GameField() = default;
signals:
	void showMainMenu();
protected slots:
	void onClickedBackButton();
	void onClickedButton() {};
private:
	QLabel* scoreLabel;
	QLabel* tilesLabel;
	QLabel* livesLabel;
	QPushButton* backButton;
	QVector<MyButton*> buttons;
};

