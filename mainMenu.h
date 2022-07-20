#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(QWidget* parent = nullptr) ;
	~MainMenu() = default;
private:
	QLabel* titleLabel;
	QPushButton* playButton;
	QLabel* scoreLabel;
	QLabel* tileLabel;
	QLabel* recordLabel;
	QLabel* maxTileLabel;
	QPushButton* infoButton;
	QPushButton* ladderButton;
};