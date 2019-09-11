#include <iostream>
#include "Creature.h"
#include "cstdlib"
#include "ctime"
#include "Weapons.h"
#include "screen.h"
using namespace std;

Creature::Creature() {
	type=0;
	strength=10;
	hitpoints=10;
	count++;
}
string Creature::getSpecies() { //Im using this so I could find the species name
	switch(type) {
		case 0:
			return "Human";
		break;
		case 1:
			return "Cyberdemon";
		break;
		case 2:
			return "Balorg";
		break;
		case 3:
			return "Elf";
		 break;
	}
	return "Unknown";
}
int Creature::getDamage() {
	int damage;//default damage
	srand(time(0));
	damage=(rand()%getStrength())+1;

//	cout<<"Hello";
	return damage;

}
void Creature::reactDamage(int attackType) {
	//for humans and elfs
	switch(attackType) {
		case 1:
			console.textSimulation("I will assure you're destruction you really think you could end me with default damage");
		break;
		case 2:
			console.textSimulation("That was more painful still I will assure my revenge");
		break;
		case 3:
			console.textSimulation("I'm on the verge of death neverless I will make sure I attack with bravery");
		break;
	}
}
