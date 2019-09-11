#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Game\screen.h"
using namespace std;
bool cool();
int main() {
	int c, w;
//	for (int x=0;x<100;x++ ) {
//	cin>>c;
//	cin>>w;
//	Beep(c, w);	
//	}
	bool check=false;
//	for(int i=0;i<4;i++) {
//		for(int x=0;x<200;x++) 
//			cout<<check;
//		cout<<endl;
//	}
string backgroundPossible[8] = {"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White"};//list of avaliable color for background
	string textColor[9] = {"Black", "Gray", "Light Blue", "Light Green", "Light Aqua", "Light Red",
		"Light Purple", "Light Yellow", "Bright White"}; //list of avaliable colors for text
	for (int i=0;i<20;i++) {
			
			if (i==10 || i==14) {
				check=true;
			}
			cout<<check;
			check=false;	
	}
	cout<<endl;
	check=false;
		for(int i=0;i<20;i++) {
			if (i==12)
				check=true;
			
			cout<<check;
			check=false;
		}
		cout<<endl;
	for(int i=0;i<20;i++) {
			if (i>=10 && i<=14)
				check=true;
			
			cout<<check;
			check=false;
		}
		srand(time(0));
	
		cout<<endl;
		Screen console;
			for(int i=0;i<1231231231231232132133213212313123123212312312321312312331223112332222222222222221231231231232312222222222;i++) {
				for (int x=0;x<8;x++) {
				
				check=rand()%2;
				cout<<check;
				console.changeColor(backgroundPossible[x], textColor[x]);
				Beep(x+i, x+5);
			}
			if(i%23==0)
			cout<<endl;
			
		}
}
bool cool() {
	bool x=rand()%2;
	return x; 
}
