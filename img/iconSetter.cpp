#include "iconSetter.h"

void IconSetter::setButtonIcon(const QString& imageUrl, double width, double height, QPushButton* button)
{
	QPixmap pixmap(imageUrl);
	QIcon buttonIcon(pixmap);
	button->setIcon(buttonIcon);
	button->setIconSize(QSize(width, height));
}