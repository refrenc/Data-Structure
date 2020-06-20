#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::operator==(const Rectangle& s) {
	if (&s == this) return true;
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width)) return true;
	else return false;
}

ostream& operator << (ostream& os, Rectangle& r) {
	os << "Position is " << r.xLow << " ";
	os << r.yLow << endl;
	os << "Height is " << r.height << endl;
	os << "Width is " << r.width << endl;
	
	return os;
}

int Rectangle::GetHeight() { return height; }
int Rectangle::GetWidth() { return width; }