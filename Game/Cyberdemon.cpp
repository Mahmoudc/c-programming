#include "Cyberdemon.h"
#include "Demon.h"
#include "Creature.h"

Cyberdemon::Cyberdemon(): Demon() {
	Creature::setType(1);
}
Cyberdemon::Cyberdemon(int s, int h) {
	Creature::setType(1);
	Creature::setHitpoints(h);
	Creature::setStrength(s);
	
}
//will use the defualt function for get damage
