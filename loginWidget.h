#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class LoginWidget : public QWidget
{
	Q_OBJECT
public:
	explicit LoginWidget(QWidget* parent = nullptr);
	~LoginWidget() = default;
private:
	QLabel* loginLabel;
	QLabel* passwordLabel;
	QLineEdit* loginEdit;
	QLineEdit* passwordEdit;
	QPushButton* loginButton;
	QPushButton* cancelButton;
};