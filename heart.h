#ifndef HEART_H
#define HEART_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Heart : public Animal
{
public:
	Heart();
	~Heart();
	void resetState();
	void automove();
};

#endif;