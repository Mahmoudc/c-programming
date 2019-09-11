#ifndef ELF_H
#define ELF_H

#include "Creature.h"
#include "Weapons.h"
class Elf : public Creature
{
	public:
		Elf();
		Elf(int, int);
		virtual int getDamage();
		virtual void setWeapon();
};

#endif
