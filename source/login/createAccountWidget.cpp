#include "createAccountWidget.h"

CreateAccountWidget::CreateAccountWidget(QWidget* parent) :parent(parent)
{
	createObjects();
	setObjectNames();

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	createMainLayout(mainLayout);

	StyleSetter::setStyle("styles/styles/createAccountWidgetStyle.qss", this);
}

void CreateAccountWidget::onClickedCancelButton()
{
	if (close())
	{
		parent->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void CreateAccountWidget::onClickedCreateAccountButton()
{
	wrongPasswordLabel->hide();

	if (checkPasswords() && checkUsers()) 
	{
		createUser();
	}
	else
	{
		return;
	}

	if (close())
	{
		parent->show();
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void CreateAccountWidget::createObjects()
{
	loginLabel = new QLabel("Login", this);
	loginEdit = new QLineEdit(this);
	passwordLabel = new QLabel("Password", this);
	passwordEdit = new QLineEdit(this);
	confirmPasswordLabel = new QLabel("Confirm password", this);
	confirmPasswordEdit = new QLineEdit(this);
	wrongPasswordLabel = new QLabel(this);
	createAccountButton = new QPushButton("Create", this);
	cancelButton = new QPushButton("Cancel", this);
}

void CreateAccountWidget::setObjectNames()
{
	loginLabel->setObjectName("createAccounLabel");
	loginEdit->setObjectName("createAccountEdit");
	passwordLabel->setObjectName("createAccounLabel");
	passwordEdit->setObjectName("createAccountEdit");
	confirmPasswordLabel->setObjectName("createAccounLabel");
	confirmPasswordEdit->setObjectName("createAccountEdit");
	createAccountButton->setObjectName("createAccountButton");
	cancelButton->setObjectName("createAccountButton");
	wrongPasswordLabel->setObjectName("wrongPasswordLabel");
}

void CreateAccountWidget::createMainLayout(QHBoxLayout* layout)
{
	wrongPasswordLabel->hide();

	passwordEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordEdit->setEchoMode(QLineEdit::Password);

	QVBoxLayout* loginFieldLayout = new QVBoxLayout(this);
	createLoginFieldLayout(loginFieldLayout);

	layout->addLayout(loginFieldLayout);
}

void CreateAccountWidget::createLoginFieldLayout(QVBoxLayout* layout)
{
	QHBoxLayout* buttonLayout = new QHBoxLayout(this);
	createButtonLayout(buttonLayout);

	layout->addWidget(loginLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(loginEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(passwordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(passwordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(confirmPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(confirmPasswordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(wrongPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);

	layout->addLayout(buttonLayout);
}

void CreateAccountWidget::createButtonLayout(QHBoxLayout* layout)
{
	layout->addWidget(createAccountButton);
	layout->addWidget(cancelButton);

	connect(createAccountButton, SIGNAL(clicked()), SLOT(onClickedCreateAccountButton()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(onClickedCancelButton()));
}

bool CreateAccountWidget::checkPasswords()
{
	if (passwordEdit->text() != confirmPasswordEdit->text())
	{
		wrongPasswordLabel->setText("the passwords are different");
		wrongPasswordLabel->show();

		return false;
	}

	return true;
}

bool CreateAccountWidget::checkUsers()
{
	std::list<User> users = User::getUsers();

	if (loginEdit->text().isEmpty() || passwordEdit->text().isEmpty() || confirmPasswordEdit->text().isEmpty())
	{
		wrongPasswordLabel->setText("all fields must be filled");
		wrongPasswordLabel->show();
		return false;
	}

	for (const User& user : users)
	{
		if (user.getLogin() == loginEdit->text().toStdString())
		{
			wrongPasswordLabel->setText("user has alredy exists");
			wrongPasswordLabel->show();

			return false;
		}
	}

	return true;
}

void CreateAccountWidget::createUser()
{
	std::ofstream output("source/user/userFiles/users.txt", std::ios::app);
	User user(loginEdit->text().toStdString(), passwordEdit->text().toStdString());

	output << user;
	output.close();
}