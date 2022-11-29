#include "Table.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
string line(int l) {
	string s = "";
	for(int i = 0; i < l; ++i) {
		s += char(196);
	}
	return s;
}
void title() {	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
            
           
	cout << "\n";
	cout << setw(45) << "" << "        ____  ____        ___     __               " << "\n";	
	cout << setw(45) << "" << "       /\\__ \\/ ___\\      /\\__\\   /__\\        " << "\n";
	cout << setw(45) << "" << "      / /  \\  /   /     / /  /__//  /             " << "\n";
	cout << setw(45) << "" << "     / /    \\/   /     / /  /___/  /              " << "\n";
	cout << setw(45) << "" << "    / /  /\\     /     / /  ____   /               " << "\n";
	cout << setw(45) << "" << "   / /  /  \\   /     / /  /   /  /                " << "\n";
	cout << setw(45) << "" << "   \\/__/    \\_/      \\/__/   /__/               " << "\n\n";
	cout << setw(45) << "" << "       M O B I L E   S T O R E                     " << "\n\n\n";
	
	
	SetConsoleTextAttribute(hConsole, 15);
}
char topLeftCorner = 218;
char leftSide = 195;
char botLeftCorner = 192;

char topRightCorner = 191;
char rightSide = 180;
char botRightCorner = 217;

char row = 196;
char col = 179;

char midMid = 197;
char botMid = 193;
char topMid = 194;

char arrow = 16;

int blue = 1;
int green = 2;
int cyan = 3;
int red = 4;
int pink = 5;
int yellow = 6;
int white = 7;
int grey = 8;
int brightblue = 9;
int brightgreen = 10;
int brightcyan = 11;
int brightred = 12;
int brightpink = 13;
int brightyellow = 14;
int brightwhite = 15;
