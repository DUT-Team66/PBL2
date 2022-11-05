
#include <string>
#include <iostream>
using namespace std;
#ifndef _TABLE_H_
#define _TABLE_H_

string line(int l) {
	string s = "";
	for(int i = 0; i < l; ++i) {
		s += char(196);
	}
	return s;
}
char topLeftCorner = 218;
char leftSide = 195;
char botLeftCorner = 192;

char topRightCorner = 191;
char rightSide = 180;
char botRightCorner = 217;

char row = 196;
char col = 179;

char topMid = 197;
char midMid = 193;
char botMid = 194;

#endif