#ifndef CONFIRMATIONEXITWIDGET_H
#define CONFIRMATIONEXITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../../fonts/fontSetter.h"
#include "../../styles/styleSetter.h"

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
	void createObjects();
	void setObjectNames();
	void createMainLayout(QVBoxLayout* layout);
	void createContentLayout(QHBoxLayout* layout);
	QWidget* parent;
	QLabel* textLabel;
	QPushButton* yesButton;
	QPushButton* noButton;
};

#endif