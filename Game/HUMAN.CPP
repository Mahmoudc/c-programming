#include "Human.h"
#include "Creature.h"
#include "screen.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
Human::Human(): Creature() {
	setType(0);
}
Human::Human(int s, int h)  {
	setStrength(s);
	setHitpoints(h);
	setType(0);
}
void Human::setWeapon() {
	do {

	Weapons::setWeapon();
//	if (countWeapon1==1) {
//	cout<<"1- Shoot Pistol"<<endl;
//	cout<<"2- Shoot rocket launcher (0 left)"<<endl;
//	cout<<"3- Throw gernades(3 only)"<<endl;
//	}
//	else if(countWeapon1!=1){

	cout<<"1- Shoot Pistol"<<endl;
	cout<<"2- Shoot rocket launcher"<<endl;
	cout<<"3- Throw gernades"<<endl;
	cin>>attackType;
	if (attackType>3 || attackType<1) {
		cout<<"Invalid attack type"<<endl;
	}
	}while(attackType>3 || attackType<1);
	weaponDamage=getDamage();
	if (attackType==1) {
		//Default damage
		console.textSimulation("Bullet deals default damage");
	}
	else if(attackType==2) {

		weaponDamage+=15;
		console.textSimulation("Rocket launcher deals additional 15 additional damage");

	}
	else if(attackType==3) {

		weaponDamage+=10;//weapons class variable
		console.textSimulation("Gernade deals 10 additional damage");

	}
		cout<<"Damage Inflicted: "<<weaponDamage<<endl;
}
//int Human::getWeapon() {
//	return 0;
//}
