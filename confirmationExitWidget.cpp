#include "confirmationExitWidget.h"

ConfirmationExitWidget::ConfirmationExitWidget(QWidget* parent)
{
	int id = QFontDatabase::addApplicationFont("fonts/Boomboom.otf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont Boomboom(family);
	setFont(Boomboom);

	setWindowFlags(Qt::FramelessWindowHint);

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

	QFile file("styles/exitWidgetStyle.qss");
	file.open(QFile::ReadOnly);
	setStyleSheet(file.readAll());
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