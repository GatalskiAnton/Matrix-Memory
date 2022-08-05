#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFontDatabase>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>

class ConfirmationExitWidget:public QWidget
{
	Q_OBJECT
public:
	explicit ConfirmationExitWidget(QWidget* parent = nullptr);
	~ConfirmationExitWidget() = default;
protected slots:
	void onClickedYesButton();
	void onClickedNoButton();
signals:
	void closeMainMenu();
private:
	QLabel* textLabel;
	QPushButton* yesButton;
	QPushButton* noButton;
};