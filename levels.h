#ifndef LEVELS_H
#define LEVELS_H

#include <QImage>
#include <QRect>
#include <QString>

using namespace std;

class Levels
{
public:
	Levels(QString, int, int);
	~Levels();

	void setPosition(int, int);
	virtual void resetState();

	bool isAppear();
	void setAppear(bool);

	int getXD();
	void setXD(int);
	int getYD();
	void setYD(int);

	//virtual void automove();

	QRect getRect();
	QImage & getImage();

protected:
	QImage image;
	QRect rect;
	bool appear;
	int xDir;
	int yDir;
};
#endif;
