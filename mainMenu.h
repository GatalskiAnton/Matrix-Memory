#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFontDatabase>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include "ladderWidget.h"
#include "confirmationExitWidget.h"

class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(QWidget* parent = nullptr) ;
	~MainMenu() = default;
protected slots :
	void onClickedPlayButton();
	void pressedOnExitButton();
	void releasedOnExitButton();
	void onClickedExitButton();
	void pressedOnLadderButton();
	void releasedOnLadderButton();
	void onClickedLadderButton();
private:
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* scoreLabel;
	QLabel* tileLabel;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QPushButton* exitButton;
	QPushButton* ladderButton;
	LadderWidget* ladderWidget;
	ConfirmationExitWidget* exitWidget;
};