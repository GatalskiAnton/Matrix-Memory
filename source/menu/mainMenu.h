#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "ladderWidget.h"
#include "confirmationExitWidget.h"
#include "../user/user.h"
#include "../login/loginWidget.h"
#include "../game/gameField.h"
#include "../../fonts/fontSetter.h"
#include "../../styles/styleSetter.h"

class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(const User &, QWidget* );
	~MainMenu() = default;
protected slots :
	void onClickedPlayButton();
	void pressedOnLadderButton();
	void releasedOnLadderButton();
	void onClickedExitButton();
	void onClickedChangeAccountButton();
	void restartGame();
private:
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QPushButton* exitButton;
	LadderWidget* ladderWidget;
	ConfirmationExitWidget* exitWidget;
	User user_;
};