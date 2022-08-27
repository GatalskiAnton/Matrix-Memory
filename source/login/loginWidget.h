#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "createAccountWidget.h"
#include "../menu/mainMenu.h"
#include "../user/user.h"
#include "../../styles/styleSetter.h"

class LoginWidget : public QWidget
{
	Q_OBJECT
public:
	explicit LoginWidget(QWidget* parent = nullptr);
	~LoginWidget() = default;
protected slots:
	void onClickedRegisterButton();
	void onClickedLoginButton();
	void onClickedCancelButton();
private:
	void createObjects();
	void setObjectNames();
	void createMainLayout(QHBoxLayout* layout);
	void createLoginFieldLayout(QVBoxLayout* layout);
	void createButtonLayout(QHBoxLayout* layout);
	void checkUser(const std::list<User>& users);
	QLabel* loginLabel;
	QLineEdit* loginEdit;
	QLabel* passwordLabel;
	QLineEdit* passwordEdit;
	QLabel* wrongPasswordLabel;
	QPushButton* registerButton;
	QPushButton* loginButton;
	QPushButton* cancelButton;
};

#endif