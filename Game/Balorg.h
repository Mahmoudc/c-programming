#ifndef BALORG_H
#define BALORG_H

#include "Demon.h"

class Balorg : public Demon
{
	public:
		Balorg();
		Balorg(int, int);
		virtual int getDamage();
};

#endif
