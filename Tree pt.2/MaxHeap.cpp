int min(const int a, const int b) {
	if (a > b) return b;
	else return a;
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

template <class T>
class MaxHeap : public MaxPQ<T> {
public:
	MaxHeap(int theCapacity = 10);
	void Push(const T& e);			//최대 힙에 e 삽입
	void Pop();						//최대 원소 삭제
private:
	int capacity;
	int heapSize;
	T* heap;
};

template<class T>
MaxHeap<T>::MaxHeap(int theCapacity) {
	if (theCapacity < 1) throw "Capacity must be >= 1";
	capacity = theCapacity;
	heapSize = 0;
	heap = new T[capacity + 1];
}

template <class T>
void MaxHeap<T>::Push(const T& e) {				//시간 복잡도 O(log n) > 완전 이진 트리 높이때문에
	if (heapSize == capacity) {
		ChangeSize1D(heap, capacity, 2 * capacity);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e) {
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop() {
	if (isEmpty()) throw "Heap is empty. Cannot delete.";
	heap[1].~T();			//최대 원소 삭제

	T lastE = heap[heapSize--];			//마지막 노드 삭제

	int currentNode = 1;
	int child = 2;
	while (child <= heapSize) {
		if (child < heapSize && heap[child] < heap[child + 1]) child++;

		if (lastE >= heap[child]) break;

		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	heap[currentNode] = lastE;
}