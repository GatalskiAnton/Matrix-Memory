#include "mainMenu.h"
#include <QFont>
#include <QFile>

MainMenu::MainMenu(QWidget* parent)
{
	setStyleSheet(
		"*{background-color: rgb(3,38,66); }"
		);

	QVBoxLayout* vbox = new QVBoxLayout(this);
	QHBoxLayout* hbox = new QHBoxLayout(this);

	vbox->setAlignment(Qt::AlignTop);
	titleLbl = new QLabel("Matrix Memory", this);
	titleLbl->setFont(QFont("Times", 50));
	titleLbl->setStyleSheet(
		"color: rgb(255,255,253);"
		);
	playBtn = new QPushButton("PLAY", this);
	playBtn->setStyleSheet(
		"QPushButton{"
		"min-width:  200px;"
		"color: rgb(255,255,253);"
		"font-size: 50px;"
		"background-color:rgb(46,202,95);"
		"width:  200px;"
		"height: 200px;"
		"border: 1.5px solid  rgb(255,255,253); "
		"border-radius: 100px;}"
		"QPushButton:pressed {"
		"font-size: 20px;}"
		);
	scoreLbl = new QLabel("Score: 0",this);
	scoreLbl->setStyleSheet(
		"color:rgb(255,255,253);"
		"font-size: 25px;"
		);
	tileLbl = new QLabel("Tile: 0");
	tileLbl->setStyleSheet(
		"color:rgb(255,255,253);"
		"font-size: 25px;"
		);
	recordLbl = new QLabel("Record: 0");
	recordLbl->setStyleSheet(
		"color:rgb(255,255,253);"
		"font-size: 25px;"
		);
	maxTileLbl = new QLabel("Max Tile: 0");
	maxTileLbl->setStyleSheet(
		"color:rgb(255,255,253);"
		"font-size: 25px;"
		);
	infoBtn = new QPushButton("i", this);
	infoBtn->setStyleSheet(
		"height:50px;"
		"width: 50px;"
		"border-radius: 25px;"
		"color:rgb(255,255,253);"
		"font-size: 40px;"
		"border: 1.5px solid  rgb(255,255,253); "
		);

	ladderBtn = new QPushButton(this);
	QPixmap pixmap("ladderIcon.png");
	QIcon ButtonIcon(pixmap);
	
	ladderBtn->setStyleSheet(
		"height:50px;"
		"width: 50px;"
		"border-radius: 25px;"
		"background: #00ff00 url(ladderIcon.png);"
		"color:rgb(255,255,253);"
		"font-size: 40px;"
		"border: 1.5px solid  rgb(255,255,253); "
		);
	ladderBtn->setIcon(ButtonIcon);
	ladderBtn->setIconSize(QSize(36,36));

	vbox->setSpacing(10);
	vbox->addWidget(titleLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->addWidget(playBtn, 0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->setSpacing(75);
	vbox->addWidget(scoreLbl,0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->addSpacing(-50);
	vbox->addWidget(tileLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->addSpacing(-50);
	vbox->addWidget(recordLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->addSpacing(-50);
	vbox->addWidget(maxTileLbl, 0, Qt::AlignTop | Qt::AlignHCenter);
	vbox->addSpacing(100);
	vbox->addWidget(infoBtn, 0, Qt::AlignLeft | Qt::AlignBottom);
	vbox->addSpacing(-129);
	vbox->addWidget(ladderBtn, 0, Qt::AlignRight | Qt::AlignBottom);
	hbox->addLayout(vbox);

}
