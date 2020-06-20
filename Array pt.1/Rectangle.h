#pragma once
#include <iostream>

using namespace std;

class Rectangle {
private:
	int xLow, yLow, height, width;
public:
	Rectangle(int x, int y, int h = 0, int w = 0) : xLow(x), yLow(y), height(h), width(w) {}
	~Rectangle() {}
	bool operator==(const Rectangle& s);
	friend ostream& operator << (ostream& os, Rectangle& r);
	int GetHeight();
	int GetWidth();
};