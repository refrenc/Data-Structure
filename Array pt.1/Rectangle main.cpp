#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
	Rectangle r(2, 2, 3, 4), s(3, 3, 3, 3);
	Rectangle* t = &s;

	if (r.GetHeight() * r.GetWidth() > t->GetHeight()* t->GetWidth())
		cout << " r ";
	else cout << " s ";
	cout << "has the greater area" << endl;

	return 0;
}