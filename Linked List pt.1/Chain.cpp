template <class T> class Chain;

template <class T>
class ChainNode {
	friend class Chain<T>;
public:
	ChainNode(int element = 0, ChainNode* next = 0) {
		data = element;
		link = next;
	}
private:
	T data;
	ChainNode<T>* link;
};

template <class T>
class Chain {
private:
	ChainNode<T>* first;
	ChainNode<T>* last;

	class ChainIterator {
	public:
		ChainIterator(ChainNode<T>* startNode = 0) {	//체인에 대한 전방 반복자
			current = startNode;
		}

		T& operator*() const { return current->data; }
		T* operator->() const { return &current->data; }

		ChainIterator& operator++() {
			current = current->lenk;
			return *this;
		}
		ChainIterator operator++(int) {
			ChainIterator old = *this;
			current = current->link;
			return old;
		}
		bool operator!=(const ChainIterator right) const {
			return current != right.current;
		}
		bool operator==(const ChainIterator right) const {
			return current == right.current;
		}
	private:
		ChainNode<T>* current;
	};
public:
	Chain() { first = 0; }
	void Create2();
	void Insert50(ChainNode* x);
	void Delete(ChainNode* x, ChainNode* y);
	ChainIterator begin() { return ChainIterator(first); }
	ChainIterator end() { return ChainIterator(0); }
	void InsertBack(const T& e);
	void Concatenate(Chain<T>& b);
	void Reverse();
};

template <class T>
void Chain<T>::Create2() {
	ChainNode<T>* second = new ChainNode<T>(20, 0);
	first = new ChainNode<T>(10, second);
}

template <class T>
void Chain<T>::Insert50(ChainNode<T>* x) {
	if (first)
		x->link = new ChainNode<T>(50, x->link);
	else
		first = new ChainNode<T>(50);
}

template <class T>
void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T>* y) {
	if (x == first) first = first->link;
	else y->link = x->link;
	delete x;
}

template <class Iterator>
void copy(Iterator start, Iterator end, Iterator to) {
	while (start != end) {
		*to = *start;
		start++;
		to++;
	}
}

template <class T>
void Chain<T>::InsertBack(const T& e) {
	if (first) {
		last->link = new ChainNode<T>(e);
		last = last->link;
	}
	else first = last = new ChainNode<T>(e);
}

template <class T>
void Chain<T>::Concatenate(Chain<T>& b) {
	if (first) {
		last->link = b.first;
		last = b.last;
	}
	else {
		first = b.first;
		last = b.last;
	}
	b.first = b.last = 0;
}

template <class T>
void Chain<T>::Reverse() {
	ChainNode<T>* current = first, *previous = 0;
	while (current) {
		ChainNode<T>* r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	first = previous;
}