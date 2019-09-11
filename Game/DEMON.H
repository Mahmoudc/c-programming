#ifndef DEMON_H
#define DEMON_H

#include "Creature.h"
#include "Weapons.h"
#include "screen.h"
class Demon : public Creature
{
	private:
		Screen console;
	public:
		Demon();
		Demon(int, int);
		virtual int getDamage();
		virtual void setWeapon();
		virtual void reactDamage(int);
};

#endif
