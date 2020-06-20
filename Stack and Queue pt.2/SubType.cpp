class Bag {
public:
	Bag(int bagCapacity = 10);
	virtual ~Bag();

	virtual int Size() const;
	virtual bool IsEmpty() const;
	virtual int Element() const;
	
	virtual void Push(const int);
	virtual void Pop();
protected:
	int* array;
	int capacity;
	int top;
};

class Stack : public Bag {
public:
	Stack(int stackCapacity = 10);
	~Stack();
	int Top() const;
	void Pop();
};

Stack::Stack(int stackCapacity) : Bag(stackCapacity) {}

Stack::~Stack() {}

int Stack::Top() const {
	if (IsEmpty()) throw "Stack is empty";
	return array[top];
}

void Stack::Pop() {
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	top--;
}