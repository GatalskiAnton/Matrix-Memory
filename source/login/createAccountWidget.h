#ifndef CREATEACCOUNTWIDGET_H
#define CREATEACCOUNTWIDGET_H

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
	void onClickedCreateAccountButton();
	void onClickedCancelButton();
private:
	void createObjects();
	void setObjectNames();
	void createMainLayout(QHBoxLayout* layout);
	void createLoginFieldLayout(QVBoxLayout* layout);
	void createButtonLayout(QHBoxLayout* layout);
	bool checkPasswords();
	bool checkUsers();
	void createUser();
	QWidget* parent;
	QLabel* loginLabel;
	QLineEdit* loginEdit;
	QLabel* passwordLabel;
	QLineEdit* passwordEdit;
	QLabel* confirmPasswordLabel;
	QLineEdit* confirmPasswordEdit;
	QLabel* wrongPasswordLabel;
	QPushButton* createAccountButton;
	QPushButton* cancelButton;
};

#endif