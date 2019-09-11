#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include "Weapons.h"
#include "screen.h"
using namespace std;
class Creature: public Weapons
{
	private:
		int type;
		int strength;//damage to inflict
		int hitpoints;//health
		string getSpecies();
		static int count;
		protected:
            Screen console;
	public:
		Creature();
		Creature(int, int, int);
		void setType(int t){
			type=t;
		}
		void setStrength(int s) {
			strength=s;
		}
		void setHitpoints(int h) {
			hitpoints=h;
		}
		int getType() {
			return type;
		}
		int getStrength() {
			return strength;
		}
		int getHitpoints() {
			return hitpoints;
		}
		virtual int getDamage();
		virtual void reactDamage(int);

		friend ostream& operator <<(ostream &o, Creature &c) {
			o<<c.getSpecies()<<endl;
			o<<"Health: "<<c.getHitpoints()<<endl;
			o<<"Strength: "<<c.getStrength()<<endl;
			return o;
		}
};

#endif

