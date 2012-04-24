#ifndef BEE_H
#define BEE_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Bee : public Animal
{
public:
	Bee();
	~Bee();
	void resetState();
	void automove();
};

#endif;