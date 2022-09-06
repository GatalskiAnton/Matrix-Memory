#include "loginWidget.h"


LoginWidget::LoginWidget(QWidget* parent)
{

	createObjects();
	setObjectNames();

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	createMainLayout(mainLayout);

	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

	StyleSetter::setStyle("styles/styles/loginWidgetStyle.qss",this);
}

void LoginWidget::onClickedRegisterButton()
{
	CreateAccountWidget* registrationWidget = new CreateAccountWidget(this);
	
	if (close())
	{
		registrationWidget->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void LoginWidget::onClickedLoginButton()
{
	wrongPasswordLabel->hide();

	std::list<User> users = User::getUsers();
	checkUser(users);
}

void LoginWidget::onClickedCancelButton()
{
	if (!close())
	{
		throw std::exception("can't close window");
	}
}

void LoginWidget::createObjects()
{
	loginLabel = new QLabel("Login", this);
	loginEdit = new QLineEdit(this);
	passwordLabel = new QLabel("Password", this);
	passwordEdit = new QLineEdit(this);
	wrongPasswordLabel = new QLabel("incorrect account name or password", this);
	registerButton = new QPushButton("create a new account");
	loginButton = new QPushButton("Login", this);
	cancelButton = new QPushButton("Cancel", this);
}

void LoginWidget::setObjectNames()
{
	loginLabel->setObjectName("loginLabel");
	loginEdit->setObjectName("loginEdit");
	passwordLabel->setObjectName("loginLabel");
	passwordEdit->setObjectName("loginEdit");
	wrongPasswordLabel->setObjectName("wrongPasswordLabel");
	registerButton->setObjectName("registerButton");
	loginButton->setObjectName("loginButton");
	cancelButton->setObjectName("loginButton");
}

void LoginWidget::createMainLayout(QHBoxLayout* layout)
{
	wrongPasswordLabel->hide();

	registerButton->setShortcutEnabled(true);

	passwordEdit->setEchoMode(QLineEdit::Password);

	QVBoxLayout* loginFieldLayout = new QVBoxLayout(this);
	createLoginFieldLayout(loginFieldLayout);

	layout->addLayout(loginFieldLayout);
}

void LoginWidget::createLoginFieldLayout(QVBoxLayout* layout)
{
	QHBoxLayout* buttonLayout = new QHBoxLayout(this);
	createButtonLayout(buttonLayout);

	layout->addWidget(loginLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(loginEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(passwordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(passwordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(wrongPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(registerButton, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addLayout(buttonLayout);
}

void LoginWidget::createButtonLayout(QHBoxLayout* layout)
{
	layout->addWidget(loginButton);
	layout->addWidget(cancelButton);

	connect(loginButton, SIGNAL(clicked()), SLOT(onClickedLoginButton()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(onClickedCancelButton()));
	connect(registerButton, SIGNAL(clicked()), SLOT(onClickedRegisterButton()));
}

void LoginWidget::checkUser(const std::list<User>& users)
{
	bool isIncorrectUser = true;

	for (User user : users)
	{
		if (loginEdit->text() == QString::fromStdString(user.getLogin()) && passwordEdit->text() == QString::fromStdString(user.getPassword()))
		{
			isIncorrectUser = false;

			if (close())
			{
				MainMenu* menu = new MainMenu(&user, this);
				menu->show();
				menu->resize(750, 900);
				menu->move(width(), height() / 2);
			}
			else
			{
				throw std::exception("can't close window");
			}
		}
	}
	if (isIncorrectUser)
	{
		wrongPasswordLabel->show();
	}
}