#ifndef HUMAN_H
#define HUMAN_H
#include "Creature.h"
#include "Weapons.h"
#include "screen.h"
class Human : public Creature
{
	private:
		Screen console;
	public:
		Human();
		Human(int, int);
		virtual void setWeapon();
};

#endif
