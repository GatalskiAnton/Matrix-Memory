#include "loginWidget.h"

LoginWidget::LoginWidget(QWidget* parent)
{
	loginLabel = new QLabel(tr("Login"), this);
	passwordLabel = new QLabel(tr("Password"), this);
	loginEdit = new QLineEdit(this);
	passwordEdit = new QLineEdit(this);
	loginButton = new QPushButton("LOGIN",this);
	cancelButton = new QPushButton("CANCEL",this);
	passwordEdit->setEchoMode(QLineEdit::Password);

	QVBoxLayout* loginFieldLayout = new QVBoxLayout(this);
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QHBoxLayout*  buttonLayout= new QHBoxLayout(this);

	buttonLayout->addWidget(loginButton);
	buttonLayout->addWidget(cancelButton);
	loginFieldLayout->addWidget(loginLabel,0,Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(loginEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addWidget(passwordEdit, 0, Qt::AlignTop | Qt::AlignLeft);
	loginFieldLayout->addLayout(buttonLayout);
	mainLayout->addLayout(loginFieldLayout);
}