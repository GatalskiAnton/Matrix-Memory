#include "mainMenu.h"
#include <QToolButton>


MainMenu::MainMenu(const User &user, QWidget* parent = nullptr):user_(user)
{
	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	scoreLabel = new QLabel("Score: " + QString::number(user_.getScore()), this);
	tileLabel = new QLabel("Tile: " + QString::number(user_.getTiles()), this);
	recordLabel = new QLabel("Record: " + QString::number(user_.getRecord()),this);
	maxTileLabel = new QLabel("Max Tile: " + QString::number(user_.getMaxTile()),this);
	ladderButton = new QPushButton(this);
	ladderWidget = new LadderWidget(this);
	exitWidget = new ConfirmationExitWidget(this);
	exitWidget->hide();

	QMenu* menu = new QMenu("123", this);
	
	QToolButton* tb = new QToolButton(this);
	tb->setMenu(menu);
	tb->setText(QString::fromStdString((user.getLogin())));
	tb->setPopupMode(QToolButton::InstantPopup);

	QAction* exitAction = new QAction("Exit",this);
	QAction* changeAccountAction = new QAction("Change account", this);
	menu->addAction(exitAction);
	menu->addAction(changeAccountAction);
	
	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	scoreLabel->setObjectName("scoreLabel");
	tileLabel->setObjectName("tileLabel");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	ladderButton->setObjectName("ladderButton");

	QPixmap pixmap("img/ladderIcon.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(36, 36));

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);

	verticalLayout->setSpacing(10);
	verticalLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(50);
	verticalLayout->addWidget(playButton, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(75);
	verticalLayout->addWidget(scoreLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-20);
	verticalLayout->addWidget(tileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-20);
	verticalLayout->addWidget(recordLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-20);
	verticalLayout->addWidget(maxTileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(50);
	verticalLayout->addWidget(tb, 0, Qt::AlignLeft | Qt::AlignBottom);
	verticalLayout->addSpacing(-90);
	verticalLayout->addWidget(ladderButton, 0, Qt::AlignRight | Qt::AlignBottom);
	horizontaLayout->addLayout(verticalLayout);

	connect(playButton, SIGNAL(clicked()), SLOT(onClickedPlayButton()));
	connect(exitAction, SIGNAL(triggered()), SLOT(onClickedExitButton()));
	connect(changeAccountAction, SIGNAL(triggered()), SLOT(onClickedChangeAccountButton()));

	connect(ladderButton, SIGNAL(pressed()), SLOT(pressedOnLadderButton()));
	connect(ladderButton, SIGNAL(released()), SLOT(releasedOnLadderButton()));
	connect(ladderButton, SIGNAL(clicked()), SLOT(onClickedLadderButton()));
	connect(ladderWidget, &LadderWidget::showMainMenu, this, &MainMenu::show);
	connect(exitWidget, &ConfirmationExitWidget::closeMainMenu, this, &MainMenu::close);

	QFile file("styles/mainMenuStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
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

void MainMenu::onClickedLadderButton()
{
	ladderWidget->show();
	ladderWidget->resize(500, 500);
	close();
}

void MainMenu::pressedOnLadderButton()
{
	QPixmap pixmap("img/ladderIconPressed.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(27, 27));
}

void MainMenu::releasedOnLadderButton()
{
	QPixmap pixmap("img/ladderIcon.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(36, 36));
}

void MainMenu::restartGame()
{
	MainMenu* newMenu = new MainMenu(user_, this);
	close();
	newMenu->show();
	newMenu->resize(750, 900);
}