#pragma once

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../../fonts/fontSetter.h"
#include "../../styles/styleSetter.h"

class LadderWidget:public QWidget
{
	Q_OBJECT
public:
	explicit LadderWidget(QWidget* parent = nullptr);
	~LadderWidget() = default;
protected slots:
	void pressedOnBackButton();
	void releasedOnBackButton();
	void onClickedBackButton();
	void pressedOnExitButton();
	void releasedOnExitButton();
	void onClickedExitButton();
signals:
	void showMainMenu(); 
private:
	QLabel* titleLabel;
	QListWidget* ladderList;
	QPushButton* backButton;
	QPushButton* exitButton;
};