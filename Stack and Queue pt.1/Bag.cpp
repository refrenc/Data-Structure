#include <iostream>
#include "Template.cpp"

using namespace std;

class Bag {						//동일한 원소가 여러번 나타남, 어떤 원소가 제거 / 삽입 되는지 문제 안됨
private:
	int* array;
	int capacity;
	int top;
public:
	Bag(int bagCapacity = 10) : capacity(bagCapacity) {
		if (capacity < 1) throw "Capacity must be > 0";
		array = new int[capacity];
		top = -1;
	}
	~Bag() {
		delete[] array;
	}

	int Size() const;
	bool IsEmpty() const;
	int Element() const;

	void Push(const int x);
	void Pop();
};

inline int Bag::Size() const { return top + 1; }

inline bool Bag::IsEmpty() const { return Size() == 0; }

inline int Bag::Element() const {			//템플릿으로 구현할 때 리턴타입 T&
	if (IsEmpty()) throw "Bag is empty";
	return array[0];
}

void Bag::Push(const int x) {				//템플릿으로 구현할 때 매개변수 T&
	if (capacity == top + 1) ChangeSize1D(array, capacity, 2 * capacity);
	capacity *= 2;
	array[++top] = x;
}

void Bag::Pop() {
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	copy(array + deletePos + 1, array + top + 1, array + deletePos);
	top--;
}