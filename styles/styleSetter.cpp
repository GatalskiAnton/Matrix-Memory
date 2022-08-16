#include "styleSetter.h"

void StyleSetter::setStyle(const QString& styleUrl, QWidget* widget)
{
	QFile file(styleUrl);
	bool success = file.open(QFile::ReadOnly);

	if (success) 
	{
		widget->setStyleSheet(file.readAll());
	}
	else 
	{
		throw std::exception("No such file");
	}
}