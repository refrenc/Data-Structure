#include "Template.cpp"

template <class T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
	void AddQueue();
private:
	T* queue;
	int front,
		rear,
		capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const { return front == rear; }

template <class T>
inline T& Queue<T>::Front() const {
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const {
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& x) {
	if ((rear + 1) % capacity == front) {
		//큐를 두배로 만드는 코드
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template <class T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty. Cannot delete";
	front = (front + 1) % capacity;
	queue[front].~T();
}

template <class T>
void Queue<T>::AddQueue() {
	T* newQueue = new T[2 * capacity];

	int start = (front + 1) % capacity;
	if (start < 2) copy(queue + start, queue + start + capacity - 1, newQueue);
	else {
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2;
	rear = capacity - 2;
	capacity *= 2;
	delete[] queue;
	queue = newQueue;
}