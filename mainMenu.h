#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFontDatabase>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QComboBox>
#include "ladderWidget.h"
#include "confirmationExitWidget.h"
#include "user.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "loginWidget.h"
#include "gameField.h"


class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(const User &, QWidget* );
	~MainMenu() = default;
protected slots :
	void onClickedPlayButton();
	void onClickedExitButton();
	void pressedOnLadderButton();
	void releasedOnLadderButton();
	void onClickedLadderButton();
	void onClickedChangeAccountButton();
	void restartGame();
private:
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* scoreLabel;
	QLabel* tileLabel;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QPushButton* ladderButton;
	LadderWidget* ladderWidget;
	ConfirmationExitWidget* exitWidget;
	User user_;
	QComboBox* box;
};