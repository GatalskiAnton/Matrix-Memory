#include "ladderWidget.h"

LadderWidget::LadderWidget(QWidget* parent)
{
	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	this->setFont(Boomboom);

	backButton = new QPushButton("Back",this);
	exitButton = new QPushButton(this);
	
	backButton->setObjectName("backButton");
	exitButton->setObjectName("exitButton");

	QPixmap pixmap("exitButtonIcon.jpg");
	QIcon buttonIcon(pixmap);
	exitButton->setIcon(buttonIcon);
	exitButton->setIconSize(QSize(25, 25));
	exitButton->setObjectName("exitButton");

	titleLabel = new QLabel("Leaderbord", this);
	titleLabel->setObjectName("titleLabel");

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);

	QFile file("styles/leaderbordStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());

	verticalLayout->setSpacing(0);
	horizontaLayout->addWidget(backButton, 0, Qt::AlignTop | Qt::AlignLeft);
	horizontaLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	horizontaLayout->addWidget(exitButton, 0, Qt::AlignTop | Qt::AlignRight);
	verticalLayout->addLayout(horizontaLayout);

	setLayout(verticalLayout);

	connect(backButton, SIGNAL(clicked()), SLOT(onClickedBackButton()));
	connect(backButton, SIGNAL(pressed()), SLOT(pressedOnBackButton()));
	connect(backButton, SIGNAL(released()), SLOT(releasedOnBackButton()));
	connect(exitButton, SIGNAL(clicked()), SLOT(onClickedExitButton()));
}

void LadderWidget::onClickedBackButton()
{
	this->close();
	emit showMainMenu();
}

void LadderWidget::pressedOnBackButton()
{
	
}

void LadderWidget::releasedOnBackButton()
{
	
}

void LadderWidget::onClickedExitButton()
{
	this->close();
}