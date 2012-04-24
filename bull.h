#ifndef BULL_H
#define BULL_H

#include <QImage>
#include <QRect>

#include "animal.h"


class Bull : public Animal
{
public:
	Bull();
	~Bull();
	void resetState();
	void automove();
};

#endif;