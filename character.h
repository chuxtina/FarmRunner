#ifndef CHARACTER_H
#define CHARACTER_H

#include <QImage>
#include <QRect>

class Character
{
public:
	Character();
	~Character();

	void resetState();
	void moveLeft(int);
	void moveRight(int);
	void moveUp(int);
	void moveDown(int);

	int getXD();
	void setXD(int);
	int getYD();
	void setYD(int);

	void automove();

	QRect getRect();
	QImage & getImage();

private:
	QImage image;
	QRect rect;
	int xD;
	int yD;
};

#endif