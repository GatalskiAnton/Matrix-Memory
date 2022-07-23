#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "ladderWidget.h"


class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(QWidget* parent = nullptr) ;
	~MainMenu() = default;

protected slots :
	void onClickedPlayButton();
	void onClickedInfoButton();
	void onClickedLadderButton();
	void pressedOnLadderButton();
	void releasedOnLadderButton();

private:
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* scoreLabel;
	QLabel* tileLabel;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QPushButton* infoButton;
	QPushButton* ladderButton;
	//InfoWidget* infoWidget;
	LadderWidget* ladderWidget;
};