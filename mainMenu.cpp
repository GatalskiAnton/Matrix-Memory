#include <QFont>
#include <QFile>
#include "mainMenu.h"

MainMenu::MainMenu(QWidget* parent)
{
	titleLabel = new QLabel("Matrix Memory", this);
	playButton = new QPushButton("PLAY", this);
	scoreLabel = new QLabel("Score: 0", this);
	tileLabel = new QLabel("Tile: 0");
	recordLabel = new QLabel("Record: 0");
	maxTileLabel = new QLabel("Max Tile: 0");
	infoButton = new QPushButton("i", this);
	ladderButton = new QPushButton(this);

	titleLabel->setObjectName("titleLabel");
	playButton->setObjectName("playButton");
	scoreLabel->setObjectName("scoreLabel");
	tileLabel->setObjectName("tileLabel");
	recordLabel->setObjectName("recordLabel");
	maxTileLabel->setObjectName("maxTileLabel");
	infoButton->setObjectName("infoButton");
	ladderButton->setObjectName("ladderButton");

	titleLabel->setFont(QFont("Times", 50));
	
	QPixmap pixmap("ladderIcon.png");
	QIcon buttonIcon(pixmap);
	ladderButton->setIcon(buttonIcon);
	ladderButton->setIconSize(QSize(36, 36));

	QFile file("style.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);
	verticalLayout->setSpacing(10);
	verticalLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addWidget(playButton, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->setSpacing(75);
	verticalLayout->addWidget(scoreLabel,0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-50);
	verticalLayout->addWidget(tileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-50);
	verticalLayout->addWidget(recordLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(-50);
	verticalLayout->addWidget(maxTileLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	verticalLayout->addSpacing(100);
	verticalLayout->addWidget(infoButton, 0, Qt::AlignLeft | Qt::AlignBottom);
	verticalLayout->addSpacing(-129);
	verticalLayout->addWidget(ladderButton, 0, Qt::AlignRight | Qt::AlignBottom);
	horizontaLayout->addLayout(verticalLayout);
}