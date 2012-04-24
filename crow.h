#ifndef CROW_H
#define CROW_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Crow : public Animal
{
public:
	Crow();
	~Crow();
	void resetState();
	void automove();
};

#endif;