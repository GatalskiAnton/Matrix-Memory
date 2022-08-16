#include "fontSetter.h"

void FontSetter::setFont(const QString& fontUrl, QWidget* widget)
{
	int fontId = QFontDatabase::addApplicationFont(fontUrl);
	
	if (fontId != -1) 
	{
		QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
		QFont font(family);
		widget->setFont(font);
	}
	else 
	{
		throw std::exception("No such font");
	}
}