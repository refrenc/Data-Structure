#include <iostream>

using namespace std;

void SelectionSort(int* a, const int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j]) j = k;
		swap(a[i], a[j]);
	}
}

template<class T>
void SelectionSort(T* a, const int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j]) j = k;
		swap(a[i], a[j]);
	}
}

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}