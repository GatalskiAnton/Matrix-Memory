#ifndef STYLESETTER_H
#define STYLESETTER_H

#include <QString>
#include <QWidget>
#include <QFile>

class StyleSetter
{
public:
	static void setStyle(const QString& styleUrl, QWidget* widget);
};

#endif