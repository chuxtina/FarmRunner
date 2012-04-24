
#ifndef DOGHOUSE_H
#define DOGHOUSE_H

#include <QImage>
#include <QRect>

class Doghouse
{
public:
	Doghouse();
	~Doghouse();

	void resetState();
	bool isHit();
	void setHit(bool);
	QRect getRect();
	void setRect(QRect);
	QImage & getImage();

private:
	QImage image;
	QRect rect;
	int x;
	int y;
	bool hit;

};

#endif