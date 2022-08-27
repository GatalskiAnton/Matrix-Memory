#include "confirmationExitWidget.h"

ConfirmationExitWidget::ConfirmationExitWidget(QWidget* parent) :parent(parent)
{
	createObjects();
	setObjectNames();

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	createMainLayout(mainLayout);

	FontSetter::setFont("fonts/fonts/Boomboom.otf", this);
	StyleSetter::setStyle("styles/styles/exitWidgetStyle.qss", this);
}

void ConfirmationExitWidget::onClickedYesButton()
{
	if (close()) 
	{
		if (!parent->close())
		{
			throw std::exception("can't close window");
		}
	}
	else
	{
		throw std::exception("can't close window");
	}
}

void ConfirmationExitWidget::onClickedNoButton()
{
	if (!close())
	{
		throw std::exception("can't close window");
	}
}

void ConfirmationExitWidget::createObjects()
{
	textLabel = new QLabel("Do you really want to quit?", this);
	yesButton = new QPushButton("Yes", this);
	noButton = new QPushButton("No", this);
}

void ConfirmationExitWidget::setObjectNames()
{
	textLabel->setObjectName("ConfirmationExitLabel");
	yesButton->setObjectName("ConfirmationExitButton");
	noButton->setObjectName("ConfirmationExitButton");
}

void ConfirmationExitWidget::createMainLayout(QVBoxLayout* layout)
{
	textLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	QHBoxLayout* contentLayout = new QHBoxLayout(this);
	createContentLayout(contentLayout);

	layout->addLayout(contentLayout);
}

void ConfirmationExitWidget::createContentLayout(QHBoxLayout* layout)
{
	layout->addWidget(textLabel, 0, Qt::AlignCenter | Qt::AlignHCenter);
	layout->addWidget(yesButton, 0, Qt::AlignBottom | Qt::AlignRight);
	layout->addWidget(noButton, 0, Qt::AlignBottom | Qt::AlignRight);

	connect(noButton, SIGNAL(clicked()), SLOT(onClickedNoButton()));
	connect(yesButton, SIGNAL(clicked()), SLOT(onClickedYesButton()));
}