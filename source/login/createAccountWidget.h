#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include "../user/user.h"
#include "../../styles/styleSetter.h"

class CreateAccountWidget :public QWidget
{
	Q_OBJECT
public:
	explicit CreateAccountWidget(QWidget* parent = nullptr);
	~CreateAccountWidget() = default;
protected slots:
	void onClickedCancelButton();
	void onClickedCreateButton();
signals:
	void showLoginWidget();
private:
	QLabel* loginLabel;
	QLabel* passwordLabel;
	QLabel* confirmPasswordLabel;
	QLineEdit* loginEdit;
	QLineEdit* passwordEdit;
	QLineEdit* confirmPasswordEdit;
	QLabel* wrongPasswordLabel;
	QPushButton* createButton;
	QPushButton* cancelButton;
};
