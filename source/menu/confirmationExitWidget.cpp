#include "confirmationExitWidget.h"

ConfirmationExitWidget::ConfirmationExitWidget(QWidget* parent)
{
	yesButton = new QPushButton("Yes", this);
	noButton = new QPushButton("No", this);
	textLabel = new QLabel("Do you really want to quit?", this);

	textLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	QHBoxLayout* horizontaLayout = new QHBoxLayout(this);

	horizontaLayout->addWidget(textLabel, 0, Qt::AlignCenter | Qt::AlignHCenter);
	horizontaLayout->addWidget(yesButton, 0, Qt::AlignBottom | Qt::AlignRight);
	horizontaLayout->addWidget(noButton, 0, Qt::AlignBottom | Qt::AlignRight);
	verticalLayout->addLayout(horizontaLayout);
	setLayout(verticalLayout);

	connect(noButton, SIGNAL(clicked()), SLOT(onClickedNoButton()));
	connect(yesButton, SIGNAL(clicked()), SLOT(onClickedYesButton()));

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/exitWidgetStyle.qss", this);
}

void ConfirmationExitWidget::onClickedYesButton()
{
	close();
	emit closeMainMenu();
}

void ConfirmationExitWidget::onClickedNoButton()
{
	close();
}