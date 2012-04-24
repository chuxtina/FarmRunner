#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Bullet : public Animal
{
public:
	Bullet();
	~Bullet();
	void resetState();
	void automove();
};

#endif;