#include "createAccountWidget.h"

CreateAccountWidget::CreateAccountWidget(QWidget* parent)
{
	loginLabel = new QLabel(tr("Login"), this);
	passwordLabel = new QLabel(tr("Password"), this);
	confirmPasswordLabel = new QLabel(tr("Confirm password"), this);
	wrongPasswordLabel = new QLabel(this);
	wrongPasswordLabel->hide();
	wrongPasswordLabel->setObjectName("wrongPasswordLabel");
	loginEdit = new QLineEdit(this);
	passwordEdit = new QLineEdit(this);
	confirmPasswordEdit = new QLineEdit(this);
	createButton = new QPushButton("Create", this);
	cancelButton = new QPushButton("Cancel", this);

	passwordEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordEdit->setEchoMode(QLineEdit::Password);

	QVBoxLayout* loginFieldLayout = new QVBoxLayout(this);
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QHBoxLayout* buttonLayout = new QHBoxLayout(this);

	buttonLayout->addWidget(createButton);
	buttonLayout->addWidget(cancelButton);
	loginFieldLayout->addWidget(loginLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(loginEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(confirmPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(confirmPasswordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(wrongPasswordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	
	loginFieldLayout->addLayout(buttonLayout);
	mainLayout->addLayout(loginFieldLayout);

	connect(createButton, SIGNAL(clicked()), SLOT(onClickedCreateButton()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(onClickedCancelButton()));

	QFile file("styles/loginWidgetStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
}

void CreateAccountWidget::onClickedCancelButton()
{
	emit showLoginWidget();
	close();
}

void CreateAccountWidget::onClickedCreateButton()
{
	wrongPasswordLabel->hide();
	if (passwordEdit->text() != confirmPasswordEdit->text())
	{
		wrongPasswordLabel->setText("the passwords are different");
		wrongPasswordLabel->show();
		return;
	}

	std::list<User> users = User::getUsers();
	for (const User& user : users)
	{
		if (user.getLogin() == loginEdit->text().toStdString() && user.getPassword() == passwordEdit->text().toStdString())
		{
			wrongPasswordLabel->setText("user has alredy exists");
			wrongPasswordLabel->show();
			return;
		}
	}

	std::ofstream output("source/user/userFiles/users.txt",std::ios::app);
	User user(loginEdit->text().toStdString(), passwordEdit->text().toStdString());
	output << user;
	output.close();
	close();
	emit showLoginWidget();
}
