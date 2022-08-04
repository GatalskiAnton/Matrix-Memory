#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "myButton.h"
#include <QVector>
#include <QGridLayout>
#include <QFile>
#include <QFontDatabase>
#include "user.h"

class GameField: public QWidget
{
	Q_OBJECT
public:
	explicit GameField(User user, QWidget* parent = nullptr, int lives = 3, int score = 0, int tiles = 0);
	~GameField() = default;
	int getScore();
	int getTiles();
protected slots:
	void onClickedBackButton();
	void onClickedButton();
private:
	QLabel* scoreLabel;
	QLabel* tilesLabel;
	QLabel* livesLabel;
	QPushButton* backButton;
	QVector<MyButton*> buttons;
	int lives_;
	QWidget* parent_;
	int score_;
	int tiles_;
	User user_;
};

