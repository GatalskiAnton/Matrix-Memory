#include "mainMenu.h"
#include <QToolButton>


MainMenu::MainMenu(User *user, QWidget* parent = nullptr):user(user)
{
	createObjects();
	setObjectNames();

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	createMainLayout(mainLayout);

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/mainMenuStyle.qss", this);
}

void MainMenu::onClickedPlayButton()
{
	GameField* gameFieldWidget = new GameField(this, user);

	if (close())
	{
		gameFieldWidget->show();
		gameFieldWidget->setFixedSize(850, 900);
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void MainMenu::onClickedExitButton()
{
	ConfirmationExitWidget* exitWidget = new ConfirmationExitWidget(this);
	exitWidget->show();
	exitWidget->resize(350, 250);
}

void MainMenu::pressedOnExitButton()
{
	QPixmap pixmap("img/exitButtonIconPressed.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(27, 27));
}

void MainMenu::releasedExitButton()
{
	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(36, 36));
}

void MainMenu::onClickedChangeAccountButton()
{
	LoginWidget* loginWidget = new LoginWidget(this);

	if (close())
	{
		loginWidget->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void MainMenu::createObjects()
{
	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	recordLabel = new QLabel("Record: " + QString::number(user->getRecord()), this);
	maxTileLabel = new QLabel("Max Tile: " + QString::number(user->getMaxTile()), this);
	loginMenuButton = new QToolButton(this);
	loginMenu = new QMenu(this);
	changeAccountAction = new QAction("Change account", this);
	exitButton = new QPushButton(this);
}

void MainMenu::setObjectNames()
{
	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	loginMenuButton->setObjectName("loginMenuButton");
	loginMenu->setObjectName("loginMenu");
	exitButton->setObjectName("exitButton");
}

void MainMenu::createMainLayout(QHBoxLayout* layout)
{
	loginMenuButton->setMenu(loginMenu);
	loginMenuButton->setText(QString::fromStdString((user->getLogin())));
	loginMenuButton->setPopupMode(QToolButton::InstantPopup);

	loginMenu->addAction(changeAccountAction);

	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(36, 36));

	QVBoxLayout* subLayout = new QVBoxLayout(this);
	createSubLayout(subLayout);

	layout->addLayout(subLayout);
}

void MainMenu::createSubLayout(QVBoxLayout* layout)
{
	layout->setSpacing(10);
	layout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(50);
	layout->addWidget(playButton, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(75);
	layout->addSpacing(-20);
	layout->addSpacing(-20);
	layout->addWidget(recordLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(-20);
	layout->addWidget(maxTileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(195);
	layout->addWidget(loginMenuButton, 0, Qt::AlignLeft | Qt::AlignBottom);
	layout->addSpacing(-108);
	layout->addWidget(exitButton, 0, Qt::AlignRight | Qt::AlignBottom);

	connect(playButton, SIGNAL(clicked()), SLOT(onClickedPlayButton()));
	connect(changeAccountAction, SIGNAL(triggered()), SLOT(onClickedChangeAccountButton()));

	connect(exitButton, SIGNAL(pressed()), SLOT(pressedOnExitButton()));
	connect(exitButton, SIGNAL(released()), SLOT(releasedExitButton()));
	connect(exitButton, SIGNAL(clicked()), SLOT(onClickedExitButton()));
}