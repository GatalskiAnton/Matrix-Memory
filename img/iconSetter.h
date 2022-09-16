#ifndef ICONSETTER_H
#define ICONSETTER_H

#include <QString>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>

class IconSetter {
public:
	static void setButtonIcon(const QString& imageUrl, double width, double heigth, QPushButton* button);
};

#endif