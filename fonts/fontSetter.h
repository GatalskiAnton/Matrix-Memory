#ifndef FONTSETTER_H
#define FONTSETTER_H

#include <QString>
#include <QWidget>
#include <QFont>
#include <QFontDatabase>

class FontSetter
{
public:
	static void setFont(const QString& fontUrl, QWidget* widget);
};

#endif