#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QFile>
#include <QFontDatabase>

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
	QPushButton* yesButton;
	QPushButton* noButton;
};

