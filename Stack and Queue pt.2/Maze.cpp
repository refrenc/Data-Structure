#include <iostream>

using namespace std;

struct offsets {
	int a, b;
};

enum directions { N, NE, E, SE, S, SW, W, NW };
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

struct Items {
	int x, y, dir;
};

template <class T>
class Stack {
public:
	Stack(int stackCapacity = 10);
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
	friend ostream& operator <<(ostream& os, Stack& r);
private:
	T* stack;				//스택 원소를 위한 배열
	int top;
	int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const {
	if (IsEmpty()) throw "Stack is empty";
	return stack[top];
}

template <class T>
void Stack<T>::Push(const T&) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
void Stack<T>::Pop() {
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	stack[top--].~T();
}

template <class T>
ostream& operator <<(ostream& os, Stack<T>& r) {
	os << "top = " << s.top << endl;
	for (int i = 0; i <= s.top; i++) {
		os << i << ":" << s.stack[i] << endl;
	}
	return os;
}

ostream& operator<<(ostream& os, Items& item) {
	return os << item.x << "," << item.y << "," << item.dir;
}

int main() {
	cout << ::move[0].a << " " << ::move[0].b;
}

void Path(const int m, const int p) {
	mark[1][1] = 1;
	Stack<Items> stack(m * p);
	Items temp(1, 1, E);
	stack.Push(temp);

	while (!stack.IsEmpty()) {
		temp = stack.Top();
		stack.Pop();
		int i = temp.x;
		int j = temp.y;
		int d = temp.dir;
		while (d < 8) {
			int g = i + ::move[d].a;
			int h = j + ::move[d].b;
			if ((g == m) && (h == p)) {
				cout << stack;
				cout << i << " " << j << endl;
				cout << m << " " << p << endl;
				return;
			}
		
			if ((!maze[g][h]) && (!mark[g][h])) {
				mark[g][h] = 1;
				temp.x = i;
				temp.y = j;
				temp.dir = d + 1;
				i = g;
				j = h;
				d = N;
			}
			else d++;
		}
	}
	cout << "No path in maze" << endl;
}