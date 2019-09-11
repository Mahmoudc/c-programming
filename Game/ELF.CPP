#include "Elf.h"
#include "Creature.h"
#include "Weapons.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Elf::Elf():Creature() {
	setType(3);
}

Elf::Elf(int s, int h) {
	setStrength(s);
	setHitpoints(h);
	setType(3);
}

int Elf::getDamage() {
	srand(time(0));
	int damage=Creature::getDamage();
	if ((rand()%10)==0) {
		cout<<"Magical attack inflicts "<<Creature::getDamage()<<" additional damage points!"<<endl;
		damage=Creature::getDamage()*2;

	}
	return damage;
}
void Elf::setWeapon() {
	do {

	Weapons::setWeapon();
	cout<<"1- Shoot bowl"<<endl;
	cout<<"2- Shoot thunder bowl"<<endl;
	cout<<"3- Shoot fire bowl"<<endl;
	cin>>attackType;
	if (attackType>3 || attackType<1) {
		cout<<"Invalid attack type"<<endl;
	}
	}while(attackType>3 || attackType<1);
	weaponDamage=getDamage();
	if (attackType==1) {
		//Default damage
		console.textSimulation("Bowl deals default damage");
	}
	else if(attackType==2) {
        console.textSimulation("Thunder bowl deals 15 additional damage");
		weaponDamage+=15;
	}
	else if(attackType==3) {
          console.textSimulation("Fire bowl deals 10 additional damage");
		weaponDamage+=10;
	}
	cout<<"Damage Inflicted: "<<weaponDamage<<endl;
}
