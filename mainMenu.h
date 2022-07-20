#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


class MainMenu : public QWidget
{
	Q_OBJECT
public:
	explicit MainMenu(QWidget* parent = nullptr) ;
	~MainMenu() = default;
private:
	QLabel* titleLbl;
	QPushButton* playBtn;
	QLabel* scoreLbl;
	QLabel* tileLbl;
	QLabel* recordLbl;
	QLabel* maxTileLbl;
	QPushButton* infoBtn;
	QPushButton* ladderBtn;
};

