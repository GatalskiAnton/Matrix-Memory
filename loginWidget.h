#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainMenu.h"
#include "user.h"


class LoginWidget : public QWidget
{
	Q_OBJECT
public:
	explicit LoginWidget(QWidget* parent = nullptr);
	~LoginWidget() = default;
protected slots:
	void onClickedLoginButton();
	void onClickedCancelButton();
private:
	QLabel* loginLabel;
	QLabel* passwordLabel;
	QLineEdit* loginEdit;
	QLineEdit* passwordEdit;
	QPushButton* registerButton;
	QPushButton* loginButton;
	QPushButton* cancelButton;
};