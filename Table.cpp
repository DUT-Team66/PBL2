#include "Table.h"

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

char midMid = 197;
char botMid = 193;
char topMid = 194;