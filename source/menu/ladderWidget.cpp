#include "ladderWidget.h"

LadderWidget::LadderWidget(QWidget* parent)
{
	int id = QFontDatabase::addApplicationFont("fonts/fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	setWindowFlags(Qt::FramelessWindowHint);

	titleLabel = new QLabel("Leaderbord", this);
	ladderList = new QListWidget(this);
	backButton = new QPushButton("Back", this);
	exitButton = new QPushButton(this);

	titleLabel->setObjectName("titleLabel");
	ladderList->setObjectName("ladderList");
	backButton->setObjectName("backButton");
	exitButton->setObjectName("exitButton");

	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(25, 25));

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);

	verticalLayout->setSpacing(0);
	horizontaLayout->addWidget(backButton, 0, Qt::AlignTop | Qt::AlignLeft);
	horizontaLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	horizontaLayout->addWidget(exitButton, 0, Qt::AlignRight | Qt::AlignTop);
	verticalLayout->addLayout(horizontaLayout);
	verticalLayout->addWidget(ladderList, 0);
	setLayout(verticalLayout);

	connect(backButton, SIGNAL(pressed()), SLOT(pressedOnBackButton()));
	connect(backButton, SIGNAL(released()), SLOT(releasedOnBackButton()));
	connect(backButton, SIGNAL(clicked()), SLOT(onClickedBackButton()));
	connect(exitButton, SIGNAL(pressed()), SLOT(pressedOnExitButton()));
	connect(exitButton, SIGNAL(released()), SLOT(releasedOnExitButton()));
	connect(exitButton, SIGNAL(clicked()), SLOT(onClickedExitButton()));

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/leaderbordStyle.qss", this);
}

void LadderWidget::onClickedBackButton()
{
	close();
	emit showMainMenu();
}

void LadderWidget::pressedOnExitButton()
{
	QPixmap pixmap("img/exitButtonIconPressed.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(20, 20));
}

void LadderWidget::releasedOnExitButton()
{
	QPixmap pixmap("img/exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(25, 25));
}

void LadderWidget::pressedOnBackButton()
{
	
}

void LadderWidget::releasedOnBackButton()
{
	
}

void LadderWidget::onClickedExitButton()
{
	close();
}