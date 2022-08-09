#include "gameField.h"

GameField::GameField(QWidget* parent,
	User* user,
	int level,
	int lives,
	int score,
	int tiles) :parent(parent),
	level(level),
	lives(lives),
	score(score),
	tiles(tiles),
	user(user)
{
	srand(time(NULL));
	
	createObjects();
	setObjectsNames();

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	createMainLayout(mainLayout);

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/gameFieldStyle.qss", this);
}

void GameField::onClickedBackButton()
{
	close();
	parent->show();
}

void GameField::onClickedTilesFieldButton()
{
	MyButton* source = (MyButton*)QObject::sender();

	switch (source->getValue())
	{
	case 0:
		onWrongButtonClicked(source);
		break;
	case 1:
		onCorrectButtonClicked(source);
		break;
	default:
		break;
	}

	updateScore();
}

void GameField::createObjects()
{
	backButton = new QPushButton("Back", this);
	scoreLabel = new QLabel("Score: " + QString::number(score), this);
	tilesLabel = new QLabel("Tiles: " + QString::number(tiles), this);
	livesLabel = new QLabel("Lives: " + QString::number(lives), this);
}

void GameField::setObjectsNames()
{
	backButton->setObjectName("gameFieldButton");
	scoreLabel->setObjectName("gameFieldLabel");
	tilesLabel->setObjectName("gameFieldLabel");
	livesLabel->setObjectName("gameFieldLabel");
}

void GameField::createMainLayout(QVBoxLayout* layout)
{
	layout->setAlignment(Qt::AlignTop);
	layout->setSpacing(150);

	QHBoxLayout* topMenuLayout = new QHBoxLayout(this);
	QGridLayout* tilesLayout = new QGridLayout(this);

	tilesLayout->setColumnStretch(0, 1);
	tilesLayout->setColumnStretch(level + 4, 1);
	tilesLayout->setSpacing(0);

	createTopMenuLayout(topMenuLayout);
	createTilesLayout(tilesLayout);

	layout->addLayout(topMenuLayout, 0);
	layout->addLayout(tilesLayout, 0);

	connect(backButton, SIGNAL(clicked()), SLOT(onClickedBackButton()));
}

void GameField::createTopMenuLayout(QHBoxLayout* layout)
{
	layout->addWidget(backButton, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(scoreLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addWidget(tilesLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	layout->addWidget(livesLabel, 0, Qt::AlignTop | Qt::AlignRight);
}

void GameField::createTilesLayout(QGridLayout* layout)
{
	int rows = 3;
	int columns = 3;

	if (level % 2)
	{
		rows += level - 1;
		columns += level;
	}
	else
	{
		rows = columns += level - 1;
	}

	if (level == 0)
	{
		rows = 3;
		columns = 3;
	}

	createButtons(rows, columns);

	for (int i = 0; i < rows * columns; ++i)
	{
		layout->addWidget(buttons[i], i / columns, i % columns + 1, Qt::AlignHCenter | Qt::AlignTop);
		connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedTilesFieldButton()));
	}
}

void GameField::createButtons(int rows, int columns)
{
	QVector<int> buttonsIndex;

	for (int i = 0; i < level + 3; ++i)
	{
		int buttonIndex = rand() % (rows * columns);

		for (int j = 0; j < buttonsIndex.length(); ++j)
		{
			if (buttonsIndex[j] == buttonIndex)
			{
				buttonIndex = rand() % (rows * columns);
			}
		}
		buttonsIndex.push_back(buttonIndex);
	}

	for (int i = 0; i < rows * columns; ++i)
	{
		bool thisButton = false;

		for (int j = 0; j < buttonsIndex.length(); ++j)
		{
			if (i == buttonsIndex[j])
			{
				thisButton = true;
			}
		}

		addButton(thisButton);
	}
}

void GameField::addButton(bool thisButton)
{
	MyButton* tempButton = thisButton ? new MyButton(this, 1) : new MyButton(this);

	tempButton->setFixedSize(width() / 6, width() / 6);
	buttons.push_back(tempButton);
}

void GameField::onCorrectButtonClicked(MyButton* source)
{
	score += 50;
	++tiles;

	source->setColor(QColor(48, 208, 112));
	source->setValue(-1);

	tryWin();
}

void GameField::tryWin() 
{
	bool isWin = true;
	for (int i = 0; i < buttons.size(); ++i)
	{
		if (buttons[i]->getValue() == 1)
		{
			isWin = false;
			break;
		}
	}

	if (isWin)
	{
		createNewLevel();
	}
}

void GameField::createNewLevel()
{
	GameField* gm = new GameField(parent, user, ++level, lives, score, tiles);
	close();
	gm->show();
	gm->setFixedSize(850, 900);
}

void GameField::onWrongButtonClicked(MyButton* source) 
{
	--lives;

	source->setColor(QColor(220, 59, 49));
	source->setEnabled(false);

	if (lives == 0)
	{
		endGame();
	}
}

void GameField::endGame()
{
	user->setScore(score);
	user->setTiles(tiles);

	if (score > user->getRecord())
	{
		user->setRecord(score);
	}

	close();
	parent->show();
}

void GameField::updateScore()
{
	scoreLabel->setText("Score: " + QString::number(score));
	tilesLabel->setText("Tiles: " + QString::number(tiles));
	livesLabel->setText("Lives: " + QString::number(lives));

	update();
}