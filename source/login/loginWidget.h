#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../menu/mainMenu.h"
#include "../user/user.h"
#include "createAccountWidget.h"
#include "../../styles/styleSetter.h"

class LoginWidget : public QWidget
{
	Q_OBJECT
public:
	explicit LoginWidget(QWidget* parent = nullptr);
	~LoginWidget() = default;
protected slots:
	void onClickedLoginButton();
	void onClickedCancelButton();
	void onClickedRegisterButton();
private:
	QLabel* loginLabel;
	QLabel* passwordLabel;
	QLineEdit* loginEdit;
	QLineEdit* passwordEdit;
	QLabel* wrongPasswordLabel;
	QPushButton* registerButton;
	QPushButton* loginButton;
	QPushButton* cancelButton;
	CreateAccountWidget* registrationWidget;
};