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
}

void GameField::onClickedBackButton()
{
	user->setScore(score);
	user->setTiles(tiles);

	updateRecord();

	if (close()) 
	{
		parent->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
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


	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/gameFieldStyle.qss", this);
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

	if (level == 0)
	{
		rows = 3;
		columns = 3;
	}
	else if (level % 2)
	{
		rows += level - 1;
		columns += level;
	}
	else
	{
		rows = columns += level - 1;
	}

	createButtons(rows, columns);

	layout->setMargin(150);

	for (int i = 0; i < rows * columns; ++i)
	{
		buttons[i]->setFixedSize(85, 85);
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

	source->setColor(new QColor(48, 208, 112));
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
	gm->move(1920 / 2 - width() / 2, 1080 / 2 - height() / 2);

	if (close())
	{
		gm->show();
		gm->setFixedSize(850, 900);
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void GameField::onWrongButtonClicked(MyButton* source) 
{
	--lives;

	source->setColor(new QColor(220, 59, 49));
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

	updateRecord();

	if (close())
	{
		parent->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void GameField::updateScore()
{
	scoreLabel->setText("Score: " + QString::number(score));
	tilesLabel->setText("Tiles: " + QString::number(tiles));
	livesLabel->setText("Lives: " + QString::number(lives));

	update();
}

void GameField::updateRecord()
{
	if (score > user->getRecord())
	{
		user->setRecord(score);
		user->setMaxTile(tiles);

		std::list<User> users = User::getUsers();
		std::ofstream output("source/user/userFiles/users.txt");

		output.clear();

		for (User user : users)
		{
			if (user.getLogin() != this->user->getLogin())
			{
				output << user;
			}
		}

		output << *user;
	}
}