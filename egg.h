#ifndef EGG_H
#define EGG_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Egg : public Animal
{
public:
	Egg();
	~Egg();
	void resetState();
	void automove();
};

#endif;