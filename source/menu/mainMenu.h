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
#include <QMenuBar>
#include <QAction>
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
public:
	explicit MainMenu(User* user, QWidget* parent );
	~MainMenu() = default;
protected slots :
	void onClickedPlayButton();
	void onClickedExitButton();
	void pressedOnExitButton();
	void releasedExitButton();
	void onClickedChangeAccountButton();
private:
	void createObjects();
	void setObjectNames();
	void createMainLayout(QHBoxLayout* layout);
	void createSubLayout(QVBoxLayout* layout);
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QToolButton* loginMenuButton;
	QMenu* loginMenu;
	QAction* changeAccountAction;
	QPushButton* exitButton;
	User* user;
};

#endif