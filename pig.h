#ifndef PIG_H
#define PIG_H

#include "animal.h"

#include <QRect>
#include <QImage>

class Pig : public Animal
{
public:
	Pig();
	~Pig();
	void resetState();
	void automove();
};

#endif;