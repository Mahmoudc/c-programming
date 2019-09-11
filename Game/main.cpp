#include <iostream>
#include "screen.h"
#include "Creature.h"
#include "Creature.cpp"//this fixed my compiler error
#include "Cyberdemon.h"
#include "Cyberdemon.cpp"
#include "Human.h"
#include "Human.cpp"
#include "Balorg.h"
#include "Balorg.cpp"
#include "Demon.h"
#include "Demon.cpp"
#include "Elf.h"
#include "Elf.cpp"
#include "Weapons.h"
#include "Weapons.cpp"
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>

//Implement display setting that allows you to change the screen color
//So I tried the best I can to do changes to the weapons class to use composition unfourtently that didn't work
//I know I'm not supposed to use inheritance for weapons class because of the has a relationship but that's the only way I got it to work
using namespace std;
int Creature::count=0;
string backgroundColor="Black";
Screen console(backgroundColor, "Bright White");//Screen will be global because all the function might make use of it

int menu();
int selectCharacter();
int selectEnemy();
bool battleArena(Creature *character, Creature *enemy, int &);//sends in potions
int settingsOptions();
void tutorialSimulation();
//Creature findCreature(int);
//extra might be removed if doesn't work
Creature *assignCharacter(int, int, int);//return an address of the creature
//end
int main() {

	//Testing phase
	//Implement potions that you can buy to restore full health
//	Human* test=new Human;
//	Human test;
//	Balorg test2;
//	int testing;
//	do {
//
//	test.setWeapon();
//	cout<<test.getWeaponDamage()<<endl;
//	test2.setWeapon();
//	cout<<test2.getWeaponDamage()<<endl;
//	cin>>testing;
//}while(testing==1);
//	Human human;

//	Balorg bell;
//	Human human;
//	Cyberdemon cyborg;
//	Demon dead;
//	Elf elf;
//	Creature dude;
//	cout<<bell.getSpecies()<<endl;
//	cout<<human.getSpecies()<<endl;
//	cout<<cyborg.getSpecies()<<endl;
//	cout<<elf.getSpecies()<<endl;
//	cout<<elf.getDamage()<<endl;
//	cout<<dead.getDamage()<<endl;//it works //ovrides the orginal get damage with a 50% chance of causing maximum deamage
//	cout<<bell.getDamage()<<endl;
//	cout<<dude.getDamage()<<endl;
//	cout<<human.getDamage()<<endl;//uses the default getDamage
	string backgroundPossible[8] = {"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White"};
	string colorChosen;
	int display;
	int originalDamage;
	int character;
	int enemy;
	int purchase;
	int points=0;
	//10 points will be added when a player wins a level, which he then can use to increase the player strength and health
	int healthPoition=0;
	int settings;
	int difficulty;
	//Default hitPoints and strenth for both enemy and human
	int hitPoints=50;
	int strength=50;
	int characterStrength=50;
	int characterHitPoints=50;
	bool passed;
	//end
	char playAgain='Y';
	backgroundColor="Black";
	do {

	display=menu();
	if (display==1)
	{
			console.clearScreen();//as if your going to a different page
			cout<<"Select Character"<<endl<<endl;
			character=selectCharacter();
			character=character-1;
			Creature *player;
			player=assignCharacter(character, characterStrength, characterHitPoints);

			cout<<*player<<endl;
			Sleep(1500);
			console.clearScreen();
			cout<<"Enemy is selecting a character"<<endl<<endl;
			enemy=selectEnemy();
			enemy=enemy-1;
			Creature *villian;
			villian=assignCharacter(enemy, strength, hitPoints);
			cout<<*villian<<endl;
			Sleep(1500);
			console.clearScreen();
			if (enemy==1 || enemy==2) {
				console.textSimulation("You'll be facing my demonic powers");
		}
			cout<<"Battle has begun"<<endl;
			originalDamage=villian->getHitpoints();
			passed=false;//sets so that you can't skip a level because of the previous iteration
			passed=battleArena(player, villian, healthPoition);

			if (passed) {
				points+=10;
				console.changeColor("Green", "Bright White");
				console.textSimulation("Congrats for winning");
				console.textSimulation("You've gained 10 additional points");
				Sleep(300);
				console.changeColor(backgroundColor, "Bright White");
				cout<<"Level 2"<<endl;

				villian->setHitpoints(hitPoints+10);
				player->setHitpoints(characterHitPoints);
				cout<<"Enemy: "<<*villian;
				console.textSimulation("Enemy gains 10 additional hitpoints");
				passed=battleArena(player, villian, healthPoition);
				if(passed) {
					points+=10;
					console.changeColor("Green", "Bright White");
					
					console.textSimulation("Congrats for winning");
					console.textSimulation("You've gained 10 additional points");
					Sleep(300);
					console.changeColor(backgroundColor, "Bright White");
					console.textSimulation("You've gained a health potion");
					healthPoition++;//increments potion if wins level 3
					cout<<"Level 3"<<endl;
					villian->setHitpoints(hitPoints+20);
					villian->setStrength(strength+10);
					player->setHitpoints(characterHitPoints);
					cout<<"Enemy: "<<*villian;
					console.textSimulation("Enemy gains 10 additional hitpoints and strength");
					passed=battleArena(player, villian, healthPoition);
					if (passed) {
                        points+=10;
                        console.textSimulation("Congrats for winning");
                        console.textSimulation("You've gained 10 additional points");
					}
				}

			}
			//at the end change the enemy health to default
			villian->setHitpoints(hitPoints);
			villian->setStrength(strength);
	}
	else if (display==2) {
        console.clearScreen();
        tutorialSimulation();
        char t;
        cout<<endl<<"Enter any key to exit"<<endl;
        t=getch();
        if (t>0) {
        console.clearScreen();
        continue;
        }
	}
	else if(display==3) {
		console.clearScreen();
		bool valid=false;
		settings=settingsOptions();
		if (settings==1)
		{
			console.clearScreen();
			do {

			cout<<"Choose difficulty level"<<endl;
			cout<<"1- Easy"<<endl;
			cout<<"2- Medium"<<endl;
			cout<<"3- Hard"<<endl;
			cin>>difficulty;
			if (difficulty<1 || difficulty>3)
			{
				cout<<"Invalid number"<<endl;
				console.clearScreen();
			}
		}while(difficulty<1 || difficulty>3);
		switch(difficulty) {
			case 1:
				hitPoints=30;
				strength=30;
			break;
			case 2:
				hitPoints=50;
				strength=50;
			break;
			case 3:
				hitPoints=70;
				strength=70;
			break;
		}

			valid=true;
		}

		else if (settings==2) {
		console.clearScreen();
		do {
		cout<<"Change display settings"<<endl;
		cout<<"Choose color:"<<endl<<endl;
		console.displayScreenColors();
		cin>>colorChosen;


		for (int i=0;i<8;i++) {
			if(colorChosen==backgroundPossible[i])
			{
				valid=true;

			}

		}

		if (!valid) {
			console.clearScreen();
			cout<<"Invalid Color"<<endl;


		}

	}while(!valid);
}

		if (valid) {
			console.clearScreen();
			backgroundColor=colorChosen;
			console.changeColor(backgroundColor, "Bright White");//it is not going to change unless valid
			//this fixed
			continue;//Initializing playAgain fixed the problem

	}//Allow user to change difficulty and flash screen
	}

	else if (display==4) {

		console.clearScreen();
		do {
		cout<<"Total Points: "<<points<<endl;
		cout <<"1. Increase health by 10"<<endl;
		cout<<"Cost: 10 points"<<endl;
		cout<<"2. Increase stength by 10"<<endl;
		cout<<"Cost: 20 points"<<endl;
		cin>>purchase;
		if(purchase<1 || purchase>2) {
			cout<<"Invalid number"<<endl;
			console.clearScreen();
		}
	}while(purchase<1 || purchase>2);
		if(purchase==1) {
			if (points>=10) {
				points-=10;
				characterHitPoints+=10;
				cout<<"Character health have increase by 10"<<endl;
				cout<<"Health: "<<characterHitPoints<<endl;
			}
			else
				console.textSimulation("Not enough points try winning more games");
			Sleep(2200);
			console.clearScreen();
			continue;
		}
		else if (purchase==2) {
			if (points>=20) {
				points-=20;
				characterStrength+=10;
				cout<<"Character strength have increase by 10"<<endl;
				cout<<"Strength: "<<characterStrength<<endl;

			}
			else
				console.textSimulation("Not enough points try winning more games");
				Sleep(2200);
				console.clearScreen();
				continue;
		}

	}

	else if (display==5) {
		cout<<display;
		break;
	}
	do {

//		if (display==3)
//			break;
	cout<<"Would you like to play again (y/n): ";
	cin>>playAgain;
	if (playAgain!='y' && playAgain!='Y' && playAgain!='N' && playAgain!='n')
		cout<<"Invalid character"<<endl<<"Choose (y/n)"<<endl;
		if (playAgain=='y' || playAgain=='Y' || playAgain=='N' || playAgain=='n') {
			break;
		}
}while(playAgain!='y' || playAgain!='Y' || playAgain!='N' || playAgain!='n');
	if (playAgain=='n' || playAgain=='N') {
		console.checkColorChange(1200);
		cout<<"Thank you for playing my game"<<endl;
		break;
		
	}
	if (playAgain=='y' || playAgain=='Y') {
		console.clearScreen();
	}
}while(playAgain=='y' || playAgain=='Y');


}
int menu() {
	int display;
	do {
	cout<<"1. Play game"<<endl;
	cout<<"2. Tutorial"<<endl;
	cout<<"3. Settings"<<endl;
	cout<<"4. Empower character"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>display;
	if (display>5 || display<1) {

		cout<<"Invalid number"<<endl;
		Sleep(300);
		console.clearScreen();

	}
}while(display>5 || display<1);
	Beep(600, 250);//adding some sound effects for clicking
	return display;
}
int selectCharacter() {
	int character;
	do {
	cout<<"1. Human"<<endl;
	cout<<"2. Cyberdemon"<<endl;
	cout<<"3. Balorg"<<endl;
	cout<<"4. Elf"<<endl;
	cin>>character;
	Beep(600, 250);
	if (character<1 || character>4) {
		cout<<"invalid number"<<endl;
	}
}while(character<1 || character>4);
}
int selectEnemy() {
	srand(time(0));
	int character=rand()%4+1;
	cout<<"1. Human"<<endl;
	cout<<"2. Cyberdemon"<<endl;
	cout<<"3. Balorg"<<endl;
	cout<<"4. Elf"<<endl;
//	for(int x=0;x<1000;x++) {
//		character=rand()%4+1;
//		cout<<character<<endl;
//	}works
	cout<<character<<endl;
	return character;



	Beep(600, 150);
//adding some sound effects for clicking
	return character;
}
int settingsOptions() {
	int selection;
	do {

	cout<<"Choose setting options"<<endl;
	cout<<"1- Change difficulty"<<endl;
	cout<<"2- Change display color"<<endl;
	cin>>selection;
	if (selection>2 || selection<1) {
		cout<<"Invalid number"<<endl;
		Sleep(500);
		console.clearScreen();

	}
}while(selection>2 || selection<1);
	return selection;

}
void tutorialSimulation() {
console.textSimulation("Welcome to our tutorial page");
console.textSimulation("In the main menu there are various options that you can choose from such as play game, tutorial,  settings, and exit");
console.textSimulation("The play game page has the main game components you can choose a character, and the computer will choose a randomized enemy");
console.textSimulation("Once that has been done you'll enter the main battle arena");
console.textSimulation("In the battle arena you could choose the attack type the character deals");
console.textSimulation("The first attack type deals default damage");
console.textSimulation("The second attack type deals 15 additional damage");
console.textSimulation("The last attack type deals 10 additional damage points");
console.textSimulation("If you deal more damage than the health opponent then you move to the next level");
console.textSimulation("Additional you gain 10 points for each level you win");
console.textSimulation("Enemy difficulty increase in each level. Enemy health increases 10 points each level until level 3 the enemy gains 10 health plus 10 strength");
console.textSimulation("Once you reach level 3 you'll gain 10 points and a health potion");
console.textSimulation("A health potion will revive you're health, you can either use it after an attack or use it in the next game");
console.textSimulation("Once the battle is done you can use the points you gained to increase character health and strength which you could do in empower character page");
console.textSimulation("Additionally you can change difficulty setting in the settings page if you think the enemy is too difficult to beat");
console.textSimulation("In difficulty if you choose easy health and strenght of enemy will be set to 30, medium health and strength will be set to 50, hard enemy health and strength will be set to 70");
console.textSimulation("The settings page allows you also to change the display settings so you can customize the background of the screen");

}
//Start of the battle
bool battleArena(Creature *character, Creature *enemy, int &potion) { //make it so that you can take in the screen color
	bool passed=false;
	int originalCharacterHealth=character->getHitpoints();//gets the orginal health
	int attackType;
	char answer;
	do {
		//To do
	//print damage inflicted for all classes
	cout<<endl<<"Player: "<<*character<<endl;
//	cout<<"Select a type of attack"<<endl;
//	cout<<"1- Shoot pistol"<<endl;//this will be replaced with weapons class object that will have all attacks for a type
//	cin>>attackType;
	character->setWeapon();
 	Beep(600, 150);
	//character.setWeapon(); //doesn't work must use virtual pointers to get this working
	enemy->setHitpoints(enemy->getHitpoints()-character->getWeaponDamage());
	console.changeColor("Green", "Bright White");//Screen effects so if human does damage lights green if enemy does damage screen turns red
	Sleep(500);
	enemy->reactDamage(character->getAttackType());//prints custom messages
//	cout<<backgroundColor<<endl;
	console.changeColor(backgroundColor, "Bright White");
	Sleep(200);
	cout<<endl<<"Villian: "<<*enemy;
	console.textSimulation("Now is my turn");
	console.changeColor("Red", "Bright White");
	Sleep(500);
	console.changeColor(backgroundColor, "Bright White");
	cout<<"Damage Inflicted: "<<enemy->getDamage()<<endl; //Must change since balorgs damage type would appear twice;
	character->setHitpoints(character->getHitpoints()-enemy->getDamage());
	if (potion>0) {
		do {
		cout<<"Health: "<<character->getHitpoints()<<endl;
		cout<<"Would you like to use your health potion (y/n)"<<endl;
		cin>>answer;
		if (answer!='y'&&answer!='Y'&& answer!='N' && answer !='n') {
		cout<<"Invalid character choose y/n"<<endl;
		}
		else if (answer=='y'||answer=='Y'|| answer=='N' || answer =='n')
			break;

	}while(1);
		if (answer=='y' || answer=='Y') {
			character->setHitpoints(originalCharacterHealth);
			potion--;
		}
	}
	if (character->getHitpoints()<=0 && enemy->getHitpoints()<=0 && character->getHitpoints()==enemy->getHitpoints()) {
		cout<<endl<<"Battle tied"<<endl;
		cout<<"Player: "<<*character<<endl;
		passed=false;
		break;
	}
	else if (character->getHitpoints()<=0 && enemy->getHitpoints()>character->getHitpoints()) {

		cout<<endl<<"Enemy won"<<endl;
		cout<<"Player: "<<*character<<endl;
		passed=false;
		break;
	}
	else if(enemy->getHitpoints()<=0 && character->getHitpoints()>enemy->getHitpoints()) {
		cout<<endl<<"You've won"<<endl;
		cout<<"Player: "<<*character<<endl;
		passed=true;
		break;
	}

}while(true);
return passed;
}

Creature *assignCharacter(int choice, int hitPoints, int strength) {
		Creature *player;
		if (choice==0) {
			Human *human=new Human(hitPoints, strength);
			player=human;
		}
		else if (choice==1) {
			Cyberdemon *cyborg=new Cyberdemon(hitPoints, strength);
			player=cyborg;
		}
		else if (choice==2) {
			Balorg *balorg=new Balorg(hitPoints, strength);
			player=balorg;
		}
		else if (choice==3) {
			Elf *elf=new Elf(hitPoints, strength);
			player=elf;
		}
		return player;
}
