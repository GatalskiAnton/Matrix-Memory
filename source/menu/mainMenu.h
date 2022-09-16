#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QAction>
#include <QMenu>
#include <QToolButton>
#include <QMenuBar>
#include <QAction>
#include "confirmationExitWidget.h"
#include "../user/user.h"
#include "../login/loginWidget.h"
#include "../game/gameField.h"
#include "../../img/iconSetter.h"
#include "../../fonts/fontSetter.h"
#include "../../styles/styleSetter.h"

class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(const User &user, QWidget* parent);
	~MainMenu() = default;
protected:
	void paintEvent(QPaintEvent* event);
protected slots :
	void onClickedPlayButton();
	void pressedOnLadderButton();
	void releasedOnLadderButton();
	void onClickedExitButton();
	void onClickedChangeAccountButton();
	void restartGame();
private:
	void createObjects();
	void setObjectNames();
	void createMainlayout(QHBoxLayout* layout);
	void createSubLayout(QVBoxLayout* layout);
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QLabel* scoreLabel;
	QLabel* tileLabel;
	QPushButton* exitButton;
	QMenu* playerMenu;
	QToolButton* playerToolButton;
	QAction* changeAccountAction;
	User user;
};

#endif