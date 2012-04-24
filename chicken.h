#ifndef CHICKEN_H
#define CHICKEN_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Chicken : public Animal
{
public:
	Chicken();
	~Chicken();
	void resetState();
	void automove();
};

#endif;