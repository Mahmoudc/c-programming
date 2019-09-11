#include "Balorg.h"
#include "Creature.h"
Balorg::Balorg(): Demon() {
	Creature::setType(2);
}
Balorg::Balorg(int s, int h) {
	Creature::setType(2);
	Creature::setHitpoints(h);
	Creature::setStrength(s);
	
}
int Balorg::getDamage() {
	int damage;
	damage=Demon::getDamage()*2;//Because they attack twice

	return damage;
}
