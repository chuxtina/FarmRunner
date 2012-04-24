#ifndef DOG_H
#define DOG_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void resetState();
	void automove();
};

#endif;