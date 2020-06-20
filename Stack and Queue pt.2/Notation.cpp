#include <iostream>

using namespace std;

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

void Eval(Expression e) {
	Stack<Token> stack;
	for (Token x = NextToken(e); x != '#'; x = NextToken(e)) {
		if (x is an operand) stack.Push(x);
		else {
			remove the correct number of operands for operator x from stack;
			perform the operations xand store the result onto the stack;
		}
	}
}

void Postfix(Expression e) {
	Stack<Token> stack;
	stack.Push('#');
	for (Token x = NextToken(e); x != '#'; x = NextToken()) {
		if (x is an operand) cout << x;
		else if (x == ')') {
			for (; stack.Top() != '('; stack.Pop())
				cout >> stack.Top();
			stack.Pop();
		}
		else {
			for (; isp(stack.Top()) <= icp(x); stack.Pop())
				cout << stack.Top();
			stack.Push(x);
		}
	}

	for (; !stack.IsEmpty(); cout << stack.Top(), stack.Pop());
	cout << endl;
}