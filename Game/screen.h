#include <iostream>
#include <sstream>
#include <windows.h> 
#ifndef SCREEN_H
#define SCREEN_H

using namespace std;
class Screen {
	private:
		string color;
		string text;
		int colorChosen;
		stringstream consoleColor;
		string backgroundPossible[8] = {"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White"};
		string textColor[9] = {"Black", "Gray", "Light Blue", "Light Green", "Light Aqua", "Light Red", 
		"Light Purple", "Light Yellow", "Bright White"};
		string colorPossible[16] = {"Light Blue", "Light Green", "Light Aqua", "Light Red", "Light Pink", "Light Yellow",
			 "Light White", "Light Grey", "Blue", "Green", "Mid Light White", "Red", "Pink", "Yellow", "White"};
	public:
	void changeTextColor(string color) {
		for(int x=1;x<16;x++) {
			if(color==colorPossible[x])
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x+1);
		}
	}
void setCordinates(int x, int y)
	{
  		COORD coord;
  		coord.X = x;
  		coord.Y = y;
  		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	void avaliableTextColor() {
		for(int x=1;x<2000;x++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
			cout<<"Hello World"<<endl;
	}
}
	void checkColorChange(int i) {
		int x=0;
		for(x=0;x<i;x++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	
		//cout<<"Awsome"<<endl;
	}
	//cout<<x;
}
void colorChangeIndex(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i+1);
}
		Screen(string c, string t) {
			color=c;
			text=t;
			
			for (int x=0;x<8;x++) {
			if (color==backgroundPossible[x] && text==textColor[0]) {
				consoleColor<<"Color "<<x<<"0";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[1]) {
				consoleColor<<"Color "<<x<<"8";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[2]) {
				consoleColor<<"Color "<<x<<"9";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[3]) {
				consoleColor<<"Color "<<x<<"A";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[4]) {
				consoleColor<<"Color "<<x<<"B";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[5]) {
				consoleColor<<"Color "<<x<<"C";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[6]) {
				consoleColor<<"Color "<<x<<"D";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[7]) {
				consoleColor<<"Color "<<x<<"E";
				system(consoleColor.str().c_str());
			}
			else if (color==backgroundPossible[x] && text==textColor[8]) {
				consoleColor<<"Color "<<x<<"F";
				system(consoleColor.str().c_str());
			}
		}
//			else if (color=="Blue" && text=="Black")
		}
		Screen() {
			color="Blue";
			text="Light Purple";
		}	
		void displayScreenColors() {
		for (int x=0;x<9;x++) {
			cout<<backgroundPossible[x]<<endl;
		}
		}
		void changeColor(string c, string t)
		{
			Screen(c, t);
		}
	void clearScreen() {
		system("CLS");
	}
	void textSimulation(char text[]) {
	int i=0;
	text[100];
	while(text[i]!='\0') {
		cout<<text[i];
		Sleep(30);
		i++;
	}
	cout<<endl;
}
	void textAnimation(char* text) {
		int width=115;
		for (int i=0;i<width;i++) {
			for(int x=0;x<i;x++) {
				cout<<"  ";
			}
		cout<<text;
		Sleep(5);
		clearScreen();
		}
		
	}
};
#endif
