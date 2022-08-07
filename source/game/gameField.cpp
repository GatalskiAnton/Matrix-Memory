#include "gameField.h"
#include <random>
#include <vector>


GameField::GameField(QWidget* parent,
	User* user,
	int level,
	int lives,
	int score,
	int tiles) :parent_(parent),
	level_(level),
	lives_(lives),
	score_(score),
	tiles_(tiles),
	user_(user)
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
	gameLayout->setColumnStretch(level_ + 4, 1);
	gameLayout->setSpacing(0);
	
	int m = 3;
	int n = 3;

	QVector<int> buttonsIndex;
	
	if (level_ % 2)
	{
		n += level_;
		m += level_ - 1;
	}
	else
	{
		m += level_ - 1;
		n = m;
	}

	for (int i = 0; i < level_ + 2; i++)
	{
		int buttonIndex = rand() % (n * m);
		for (int j = 0; j < buttonsIndex.length(); j++)
		{
			if (buttonsIndex[j] == buttonIndex)
			{
				buttonIndex = rand() % (n * m);
			}
		}

		buttonsIndex.push_back(buttonIndex);
	}

	for (int i = 0; i < n*m; i++)
	{
		bool thisButton = false;
		for (int j = 0; j < buttonsIndex.length(); j++)
		{
			if (i == buttonsIndex[j])
			{
				thisButton = true;
			}
		}

		MyButton* tempButton;

		if (thisButton == true)
		{
			tempButton = new MyButton(this, 1);
		}
		else
		{
			 tempButton = new MyButton(this);
		}

		tempButton->setFixedSize(width() / 6, width() / 6);
		buttons.push_back(tempButton); 
	}

	for (int i = 0; i < m*n; ++i)
	{
		gameLayout->addWidget(buttons[i], i / n, i % n + 1, Qt::AlignHCenter | Qt::AlignTop);
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
	parent_->show();
}

void GameField::onClickedFieldButton()
{
	MyButton* source = (MyButton*)QObject::sender();

	if (source->getValue() == 1)
	{
		score_ += 50;
		++tiles_;

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
			GameField* gm = new GameField(parent_, user_, ++level_, lives_, score_, tiles_);
			close();
			gm->show();
			gm->setFixedSize(850, 900);
		}
	}
	else if (source->getValue() == 0)
	{
		--lives_;

		source->setColor(QColor(220, 59, 49));
		source->setEnabled(false);

		if (lives_ == 0)
		{
			user_->setScore(score_);
			user_->setTiles(tiles_);
			close();
			parent_->show();
		}
		else if (score_ > user_->getRecord())
		{
			user_->setRecord(score_);
		}
	}

	scoreLabel->setText("Score: " + QString::number(score_));
	tilesLabel->setText("Tiles: " + QString::number(tiles_));
	livesLabel->setText("Lives: " + QString::number(lives_));
	update();
}