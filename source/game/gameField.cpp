#include "gameField.h"

GameField::GameField(QWidget* parent,
	User* user,
	int lives,
	int score,
	int tiles) :parent(parent),
	lives(lives),
	score(score),
	tiles(tiles),
	user(user)
{
	srand(time(NULL));

	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	backButton = new QPushButton("Back", this);
	scoreLabel = new QLabel("Score: " + QString::number(score), this);
	tilesLabel = new QLabel("Tiles: " + QString::number(tiles), this);
	livesLabel = new QLabel("Lives: " + QString::number(lives), this);

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontalLayout = new QHBoxLayout(this);
	QGridLayout* gameLayout = new QGridLayout();

	verticalLayout->setAlignment(Qt::AlignTop);
	verticalLayout->setSpacing(150);

	horizontalLayout->addWidget(backButton, 0, Qt::AlignTop | Qt::AlignLeft);
	horizontalLayout->addWidget(scoreLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	horizontalLayout->addWidget(tilesLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
	horizontalLayout->addWidget(livesLabel, 0, Qt::AlignTop | Qt::AlignRight);

	gameLayout->setColumnStretch(0, 1);
	gameLayout->setColumnStretch(4, 1);
	gameLayout->setSpacing(0);
	for (int i = 0; i < 9; ++i)
	{
		MyButton* tempButton = new MyButton(this,rand() % 2);
		tempButton->setFixedSize(550/3, 550/3);
		buttons.push_back(tempButton);
		gameLayout->addWidget(buttons[i], i / 3, i % 3 + 1, Qt::AlignHCenter | Qt::AlignTop);
		connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedFieldButton()));
	}

	verticalLayout->addLayout(horizontalLayout, 0);
	verticalLayout->addLayout(gameLayout, 0);

	QFile file("styles/gameFieldStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());

	connect(backButton, SIGNAL(clicked()), SLOT(onClickedBackButton()));
}

void GameField::onClickedBackButton()
{
	close();
	parent->show();
}

void GameField::onClickedFieldButton()
{
	MyButton* source = (MyButton*)QObject::sender();

	if (source->getValue() == 1)
	{
		score += 50;
		++tiles;

		source->setColor(QColor(48, 208, 112));
		source->setValue(-1);

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
			GameField* gm = new GameField(parent, user, lives, score, tiles);
			close();
			gm->show();
			gm->setFixedSize(850, 900);
		}
	}
	else if (source->getValue() == 0)
	{
		--lives;

		source->setColor(QColor(220, 59, 49));
		source->setEnabled(false);

		if (lives == 0)
		{
			close();
			parent->show();
		}
		else if (score > user->getRecord())
		{
			user->setRecord(score);
		}
	}

	scoreLabel->setText("Score: " + QString::number(score));
	tilesLabel->setText("Tiles: " + QString::number(tiles));
	livesLabel->setText("Lives: " + QString::number(lives));
	update();
}