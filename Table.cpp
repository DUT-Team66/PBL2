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