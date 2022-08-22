#include "mainMenu.h"
#include <QToolButton>


MainMenu::MainMenu(const User &user, QWidget* parent = nullptr):user_(user)
{
	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	recordLabel = new QLabel("Record: " + QString::number(user_.getRecord()),this);
	maxTileLabel = new QLabel("Max Tile: " + QString::number(user_.getMaxTile()),this);
	exitButton = new QPushButton(this);
	ladderWidget = new LadderWidget(this);
	exitWidget = new ConfirmationExitWidget(this);
	exitWidget->hide();

	QMenu* menu = new QMenu("123", this);
	
	QToolButton* tb = new QToolButton(this);
	tb->setMenu(menu);
	tb->setText(QString::fromStdString((user.getLogin())));
	tb->setPopupMode(QToolButton::InstantPopup);

	QAction* changeAccountAction = new QAction("Change account", this);
	menu->addAction(changeAccountAction);
	
	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	exitButton->setObjectName("ladderButton");

	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(36, 36));

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);

	verticalLayout->setSpacing(10);
	verticalLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(50);
	verticalLayout->addWidget(playButton, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(75);
	verticalLayout->addSpacing(-20);
	verticalLayout->addSpacing(-20);
	verticalLayout->addWidget(recordLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-20);
	verticalLayout->addWidget(maxTileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(195);
	verticalLayout->addWidget(tb, 0, Qt::AlignLeft | Qt::AlignBottom);
	verticalLayout->addSpacing(-108);
	verticalLayout->addWidget(exitButton, 0, Qt::AlignRight | Qt::AlignBottom);
	horizontaLayout->addLayout(verticalLayout);

	connect(playButton, SIGNAL(clicked()), SLOT(onClickedPlayButton()));
	connect(changeAccountAction, SIGNAL(triggered()), SLOT(onClickedChangeAccountButton()));

	connect(exitButton, SIGNAL(pressed()), SLOT(pressedOnLadderButton()));
	connect(exitButton, SIGNAL(released()), SLOT(releasedOnLadderButton()));
	connect(exitButton, SIGNAL(clicked()), SLOT(onClickedExitButton()));
	connect(ladderWidget, &LadderWidget::showMainMenu, this, &MainMenu::show);
	connect(exitWidget, &ConfirmationExitWidget::closeMainMenu, this, &MainMenu::close);

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/mainMenuStyle.qss", this);
}

void MainMenu::onClickedPlayButton()
{
	GameField* gameFieldWidget = new GameField(this, &user_);
	close();
	gameFieldWidget->show();
	gameFieldWidget->setFixedSize(850, 900);
}

void MainMenu::onClickedChangeAccountButton()
{
	LoginWidget* loginWidget = new LoginWidget(this);
	close();
	loginWidget->show();
}

void MainMenu::onClickedExitButton()
{
	exitWidget->show();
	exitWidget->resize(350, 250);
}

void MainMenu::pressedOnLadderButton()
{
	QPixmap pixmap("img/exitButtonIconPressed.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(27, 27));
}

void MainMenu::releasedOnLadderButton()
{
	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(36, 36));
}

void MainMenu::restartGame()
{
	MainMenu* newMenu = new MainMenu(user_, this);
	close();
	newMenu->show();
	newMenu->resize(750, 900);
}