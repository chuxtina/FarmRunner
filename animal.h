#ifndef ANIMAL_H
#define ANIMAL_H

#include <QImage>
#include <QRect>
#include <QString>

using namespace std;

class Animal
{
public:
	Animal(QString, int, int);
	~Animal();

	void setPosition(int, int);
	virtual void resetState();
	void moveLeft(int);
	void moveRight(int);
	void moveUp(int);
	void moveDown(int);

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

#endif