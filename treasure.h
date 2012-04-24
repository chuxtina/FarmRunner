#ifndef TREASURE_H
#define TREASURE_H

#include <QImage>
#include <QRect>

class Treasure
{
public:
	Treasure();
	~Treasure();

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