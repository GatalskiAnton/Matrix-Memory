#include "mainMenu.h"

MainMenu::MainMenu(const User& user, QWidget* parent = nullptr) :user(user)
{
	createObjects();
	setObjectNames();

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	createMainlayout(mainLayout);
}

void MainMenu::paintEvent(QPaintEvent* event)
{
	scoreLabel->setText("Score: " + QString::number(user.getScore()));
	tileLabel->setText("Tiles: " + QString::number(user.getTiles()));
	recordLabel->setText("Record: " + QString::number(user.getRecord()));
	maxTileLabel->setText("Max Tiles: " + QString::number(user.getMaxTile()));
}
void MainMenu::onClickedPlayButton()
{
	GameField* gameFieldWidget = new GameField(this, &user);
	if (close())
	{
		gameFieldWidget->show();
		gameFieldWidget->setFixedSize(850, 900);
		gameFieldWidget->move(1920 / 2 - width() / 2, 1080 / 2 - height() / 2);
	}
	else
	{
		throw std::exception("Can't close window");
	}
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
		throw std::exception("Can't close window");
	}
}

void MainMenu::onClickedExitButton()
{
	ConfirmationExitWidget* exitWidget = new ConfirmationExitWidget(this);
	exitWidget->show();
	exitWidget->resize(350, 250);
}

void MainMenu::pressedOnLadderButton()
{
	IconSetter::setButtonIcon("img/img/exitButtonIconPressed.jpg", 27, 27, exitButton);
}

void MainMenu::releasedOnLadderButton()
{
	IconSetter::setButtonIcon("img/img/exitButtonIcon.jpg", 36, 36, exitButton);
}

void MainMenu::restartGame()
{
	MainMenu* newMenu = new MainMenu(user, this);
	if (close())
	{
		newMenu->show();
		newMenu->resize(750, 900);
	}
	else
	{
		throw std::exception("Can't close window");
	}
}

void MainMenu::createObjects()
{
	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	scoreLabel = new QLabel(this);
	tileLabel = new QLabel(this);
	recordLabel = new QLabel(this);
	maxTileLabel = new QLabel(this);
	exitButton = new QPushButton(this);
	playerMenu = new QMenu(this);
	playerToolButton = new QToolButton(this);
	changeAccountAction = new QAction("Change account", this);
}

void MainMenu::setObjectNames()
{
	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	scoreLabel->setObjectName("scoreLabel");
	tileLabel->setObjectName("tileLabel");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	exitButton->setObjectName("exitButton");
	playerMenu->setObjectName("playerMenu");
	playerToolButton->setObjectName("playerToolButton");
	changeAccountAction->setObjectName("changeAccountAction");
}

void MainMenu::createMainlayout(QHBoxLayout* layout)
{
	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	createSubLayout(verticalLayout);
	layout->addLayout(verticalLayout);

	playerToolButton->setMenu(playerMenu);
	playerToolButton->setText(QString::fromStdString((user.getLogin())));
	playerToolButton->setPopupMode(QToolButton::InstantPopup);

	playerMenu->addAction(changeAccountAction);

	connect(playButton, SIGNAL(clicked()), SLOT(onClickedPlayButton()));
	connect(changeAccountAction, SIGNAL(triggered()), SLOT(onClickedChangeAccountButton()));
	connect(exitButton, SIGNAL(pressed()), SLOT(pressedOnLadderButton()));
	connect(exitButton, SIGNAL(released()), SLOT(releasedOnLadderButton()));
	connect(exitButton, SIGNAL(clicked()), SLOT(onClickedExitButton()));

	IconSetter::setButtonIcon("img/img/exitButtonIcon.jpg", 36, 36, exitButton);
	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/mainMenuStyle.qss", this);
}

void MainMenu::createSubLayout(QVBoxLayout* layout)
{
	layout->setSpacing(10);
	layout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(50);
	layout->addWidget(playButton, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(75);
	layout->addSpacing(-20);
	layout->addWidget(scoreLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(-10);
	layout->addWidget(tileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(-10);
	layout->addWidget(recordLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(-10);
	layout->addWidget(maxTileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addSpacing(195);
	layout->addWidget(playerToolButton, 0, Qt::AlignLeft | Qt::AlignBottom);
	layout->addSpacing(-68);
	layout->addWidget(exitButton, 0, Qt::AlignRight | Qt::AlignBottom);
}