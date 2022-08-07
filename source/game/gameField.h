#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QFontDatabase>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFile>
#include "../user/user.h"
#include "myButton.h"

class GameField : public QWidget
{
	Q_OBJECT
public:
	explicit GameField(QWidget* parent = nullptr,
		User* user = nullptr,
		int level = 1,
		int lives = 3,
		int score = 0,
		int tiles = 0);
	~GameField() = default;
protected slots:
	void onClickedBackButton();
	void onClickedFieldButton();
private:
	QWidget* parent_;
	User* user_;
	int level_;
	int lives_;
	int score_;
	int tiles_;
	QPushButton* backButton;
	QLabel* scoreLabel;
	QLabel* tilesLabel;
	QLabel* livesLabel;
	QVector<MyButton*> buttons;
};

#endif