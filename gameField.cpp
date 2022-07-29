#include "gameField.h"

GameField::GameField(QWidget* parent)
{
	scoreLabel = new QLabel("Score", this);
	tilesLabel = new QLabel("Tiles", this);
	livesLabel = new QLabel("Lives", this);
	backButton = new QPushButton("Back", this);

	QGridLayout* layout = new QGridLayout();
	for (int i = 0; i < 9; ++i) {
		MyButton* tempButton = new MyButton();
		tempButton->setFixedSize(tempButton->width() /5, tempButton->width()/5);
		buttons.push_back(tempButton);
		layout->addWidget(buttons[i], i/3, i % 3,Qt::AlignHCenter | Qt::AlignTop);
		connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedButton()));
	}
	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	verticalLayout->setAlignment(Qt::AlignTop);
	verticalLayout->setSpacing(150);
	QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
	horizontalLayout->addWidget(backButton,0,Qt::AlignTop | Qt::AlignLeft);
	horizontalLayout->addWidget(scoreLabel,0,Qt::AlignTop | Qt::AlignHCenter);
	horizontalLayout->addWidget(tilesLabel,0,Qt::AlignTop | Qt::AlignHCenter);
	horizontalLayout->addWidget(livesLabel,0,Qt::AlignTop | Qt::AlignRight);
	verticalLayout->addLayout(horizontalLayout,0);
	verticalLayout->addLayout(layout, 0);

	connect(backButton, SIGNAL(clicked()), SLOT(onClickedBackButton()));
}

void GameField::onClickedBackButton()
{
	close();
	emit showMainMenu();
}
