#include "mainMenu.h"

MainMenu::MainMenu(const User &user, QWidget* parent = nullptr)
{
	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	scoreLabel = new QLabel("Score: 0", this);
	tileLabel = new QLabel("Tile: 0");
	recordLabel = new QLabel("Record: 0");
	maxTileLabel = new QLabel("Max Tile: 0");
	ladderButton = new QPushButton(this);
	ladderWidget = new LadderWidget(this);
	exitWidget = new ConfirmationExitWidget(this);
	exitWidget->hide();

	QMenu* menu = new QMenu(QString::fromStdString(user.getLogin()), this);
	QMenuBar* menuBar = new QMenuBar(this);
	menuBar->setObjectName("menuBar");
	menuBar->setDefaultUp(true);

	QAction* exitAction = new QAction("Exit",this);
	QAction* changeAccountAction = new QAction("Change account", this);
	menu->addAction(exitAction);
	menu->addAction(changeAccountAction);
	menuBar->addMenu(menu);

	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	scoreLabel->setObjectName("scoreLabel");
	tileLabel->setObjectName("tileLabel");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	ladderButton->setObjectName("ladderButton");

	QPixmap pixmap("ladderIcon.png");
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
	verticalLayout->addWidget(menuBar, 0, Qt::AlignLeft | Qt::AlignBottom);
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
	QPixmap pixmap("ladderIconPressed.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(27, 27));
}

void MainMenu::releasedOnLadderButton()
{
	QPixmap pixmap("ladderIcon.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(36, 36));
}