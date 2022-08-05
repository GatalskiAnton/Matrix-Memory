#include "loginWidget.h"


LoginWidget::LoginWidget(QWidget* parent)
{
	registrationWidget = new CreateAccountWidget(this);

	loginLabel = new QLabel(tr("Login"), this);
	passwordLabel = new QLabel(tr("Password"), this);
	loginEdit = new QLineEdit(this);
	passwordEdit = new QLineEdit(this);
	wrongPasswordLabel = new QLabel("incorrect account name or password", this);
	registerButton = new QPushButton("create a new account");
	loginButton = new QPushButton("Login", this);
	cancelButton = new QPushButton("Cancel", this);

	wrongPasswordLabel->hide();

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
	loginFieldLayout->addWidget(wrongPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(registerButton, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addLayout(buttonLayout);
	mainLayout->addLayout(loginFieldLayout);

	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

	connect(loginButton, SIGNAL(clicked()), SLOT(onClickedLoginButton()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(onClickedCancelButton()));
	connect(registerButton, SIGNAL(clicked()), SLOT(onClickedRegisterButton()));

	connect(registrationWidget, &CreateAccountWidget::showLoginWidget, this, &LoginWidget::show);


	QFile file("styles/loginWidgetStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
}

void LoginWidget::onClickedLoginButton()
{
	wrongPasswordLabel->hide();

	std::list<User> users = User::getUsers();
	bool isIncorrectUser = true;

	for (const User& user : users)
	{
		if (loginEdit->text() == QString::fromStdString(user.getLogin()) && passwordEdit->text() == QString::fromStdString(user.getPassword()))
		{
			isIncorrectUser = false;

			close();
			MainMenu* menu = new MainMenu(user,this);
			menu->show();
			menu->resize(750, 900);
			menu->move(width(), height() / 2);
		}
	}
	if (isIncorrectUser) 
	{
		wrongPasswordLabel->show();
	}
}

void LoginWidget::onClickedCancelButton()
{
	close();
}

void LoginWidget::onClickedRegisterButton()
{
	registrationWidget->show();
	close();
}