#include "gameField.h"

GameField::GameField(User user, QWidget* parent, int lives, int score, int tiles):lives_(lives), score_(score), tiles_(tiles),user_(user)
{
	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	srand(time(NULL));
	scoreLabel = new QLabel("Score: " + QString::number(score_), this);
	tilesLabel = new QLabel("Tiles: " + QString::number(tiles_), this);
	livesLabel = new QLabel("Lives: " + QString::number(lives_), this);
	backButton = new QPushButton("Back", this);

	parent_ = parent;

	QGridLayout* layout = new QGridLayout();

	layout->setColumnStretch(0, 1);
	layout->setColumnStretch(4, 1);

	layout->setVerticalSpacing(0);
	layout->setHorizontalSpacing(0);
	for (int i = 0; i < 9; ++i) 
	{
		MyButton* tempButton = new MyButton(rand() % 2);
		tempButton->setFixedSize(tempButton->width() /5, tempButton->width()/5);
		buttons.push_back(tempButton);
		layout->addWidget(buttons[i], i/3 , i % 3 + 1,Qt::AlignHCenter | Qt::AlignTop);
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

	QFile file("styles/gameFieldStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
}

int GameField::getScore()
{
	return score_;
}

int GameField::getTiles()
{
	return tiles_;
}

void GameField::onClickedBackButton()
{
	close();
	parent_->show();
}

void GameField::onClickedButton()
{
	MyButton* source = (MyButton*)QObject::sender();
	if (source->getValue() == 1)
	{
		score_ += 50;
		++tiles_;
		source->setColor(QColor(48, 208, 112));
		source->update();
		source->setValue(-1);
		bool isWin = true;
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i]->getValue() == 1)
			{
				isWin = false;
				break;
			}
		}
		if (isWin)
		{
			GameField* gm = new GameField(user_, parent_, lives_, score_, tiles_);
			close();
			gm->show();
			gm->setFixedSize(850, 900);

		}
	}
	if (source->getValue() == 0)
	{
		source->setColor(QColor(220,59,49));
		source->update();
		--lives_;
		if (lives_ == 0)
		{
			close();
			parent_->show();
		}

		if (score_ > user_.getRecord())
		{
			user_.setRecord(score_);
		}
	}
	scoreLabel->setText("Score: " + QString::number(score_));
	tilesLabel->setText("Tiles: " + QString::number(tiles_));
	livesLabel->setText("Lives: " + QString::number(lives_));
}
