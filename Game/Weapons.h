#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>
using namespace std;
//#include "Creature.h"
//Each character is going to have his own weapon system depending on the character

//Human
//Shoot Pistol default damage
//Shoot rocket launcher(1 only) +15 damage
//Throw gernade (3 only) + 10 damage

//Demons in general
//laser default damage
//Lighting(1 only) +15 damage
//Fireball(3 only) +10 damage

//Elves
//Shoot bowl default damage
//Shoot Thunder bowl(1 only) +15 damage
//Shoot fire bowl(3 only) +10 damage
class Weapons 
{
	protected:
		int attackType;
		int weaponDamage;
	public:
		virtual void setWeapon();
		virtual int getWeaponDamage();
		virtual int getAttackType();
};

#endif
