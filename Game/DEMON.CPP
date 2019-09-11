#include "Demon.h"
#include "Creature.h"
#include "Weapons.h"
#include <iostream>
#include <cstdlib>
#include "screen.h"
#include <ctime>
using namespace std;

Demon::Demon() {
	setHitpoints(20);
	setStrength(20);
	setType(1);

}
int Demon::getDamage() {
	srand(time(0));
	int creatureDamage=Creature::getDamage();//uses orginal one unless 50% chance arrives
	int damage=creatureDamage;
//	cout<<"Hello"<<endl;
	if((rand()%100)<5)
	{
		cout<<"Demonic attack inflicts 50 additional damage points!"<<endl;
		damage+=50;

	}
	return damage;
}

void Demon::setWeapon() {
	do {

	Weapons::setWeapon();
	//must do data validation

	cout<<"1- Laser"<<endl;
	cout<<"2- Lightning"<<endl;
	cout<<"3- Fireball"<<endl;
	cin>>attackType;
	if (attackType>3 || attackType<1) {
		cout<<"Invalid attack type"<<endl;
	}
	}while(attackType>3 || attackType<1);
	weaponDamage=getDamage();//default dmage
	if(attackType==2) {
        console.textSimulation("Lightning deals 15 additional damage");
		weaponDamage+=15;
	}
	else if(attackType==3) {
		weaponDamage+=10;
        console.textSimulation("Fireball deals 10 additional damage");
	}
	else if(attackType==1) {
        console.textSimulation("Laser deals default damage");
	}
	cout<<"Damage Inflicted: "<<weaponDamage<<endl;
	if (getType()==2) {
		cout<<"Balorgs speed attacks inflicts "<<Creature::getDamage()<<" additional damage points! "<<endl;
	}


}
void Demon::reactDamage(int attackType) {

	switch(attackType) {
		case 1:
			console.textSimulation("You're a loser you think you could defeat my demonic powers with defualt damage");
		break;
		case 2:
			console.textSimulation("You're attack is painful you're taking life away from me Im going to take revenge");
		break;
		case 3:
			console.textSimulation("That was one hell of a painful attack but I'm going to attack you with me outmost power");
	}
}
