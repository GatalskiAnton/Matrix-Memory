#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "../user/user.h"
#include "myButton.h"
#include "../../fonts/fontSetter.h"
#include "../../styles/styleSetter.h"

class GameField : public QWidget
{
	Q_OBJECT
public:
	explicit GameField(QWidget* parent = nullptr,
		User* user = nullptr,
		int level = 0,
		int lives = 3,
		int score = 0,
		int tiles = 0);
	~GameField() = default;
protected slots:
	void onClickedBackButton();
	void onClickedTilesFieldButton();
private:
	void createObjects();
	void setObjectsNames();
	void createMainLayout(QVBoxLayout* layout);
	void createTopMenuLayout(QHBoxLayout* layout);
	void createTilesLayout(QGridLayout* layout);
	void createButtons(int rows, int columns);
	void addButton(bool thisButton);
	void onCorrectButtonClicked(MyButton* source);
	void tryWin();
	void createNewLevel();
	void onWrongButtonClicked(MyButton* source);
	void endGame();
	void updateScore();
	void updateRecord();
	QWidget* parent;
	User* user;
	int level;
	int lives;
	int score;
	int tiles;
	QPushButton* backButton;
	QLabel* scoreLabel;
	QLabel* tilesLabel;
	QLabel* livesLabel;
	QVector<MyButton*> buttons;
};



#endif