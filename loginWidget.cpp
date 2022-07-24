#include "loginWidget.h"
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget* parent)
{
	loginLabel = new QLabel(tr("Login"), this);
	passwordLabel = new QLabel(tr("Password"), this);
	loginEdit = new QLineEdit(this);
	passwordEdit = new QLineEdit(this);
	registerButton = new QPushButton("create a new account");
	loginButton = new QPushButton("Login", this);
	cancelButton = new QPushButton("Cancel", this);

	registerButton->setObjectName("registerButton");

	passwordEdit->setEchoMode(QLineEdit::Password);

	QVBoxLayout* loginFieldLayout = new QVBoxLayout(this);
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QHBoxLayout* buttonLayout = new QHBoxLayout(this);

	buttonLayout->addWidget(loginButton);
	buttonLayout->addWidget(cancelButton);
	loginFieldLayout->addWidget(loginLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(loginEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(registerButton, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addLayout(buttonLayout);
	mainLayout->addLayout(loginFieldLayout);

	connect(loginButton, SIGNAL(clicked()), SLOT(onClickedLoginButton()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(onClickedCancelButton()));

	QFile file("styles/loginWidgetStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
}

void LoginWidget::onClickedLoginButton()
{
	std::list<User> users = User::getUsers();

	for (const User& user : users)
	{
		if (loginEdit->text() == QString::fromStdString(user.getLogin()) && passwordEdit->text() == QString::fromStdString(user.getPassword()))
		{
			close();
			MainMenu* menu = new MainMenu(this);
			menu->show();
			menu->resize(750, 900);
		}
	}
}

void LoginWidget::onClickedCancelButton()
{
	close();
}