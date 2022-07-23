#pragma once
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCommonStyle>
#include <QFontDatabase>
#include <QFont>

class LadderWidget:public QWidget
{
	Q_OBJECT

public:
	explicit LadderWidget(QWidget* parent = nullptr);
	~LadderWidget() = default;
protected slots:
	void onClickedBackButton();
	void pressedOnBackButton();
	void releasedOnBackButton();
	void onClickedExitButton();
signals:
	void showMainMenu(); 

private:
	QLabel* titleLabel;
	QListWidget* ladderList;
	QPushButton* backButton;
	QPushButton* exitButton;
};

