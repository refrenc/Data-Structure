template <class T>
void CircularList<T>::InsertFront(const T& e) {
	ChainNode<T>* newNode = new ChainNode<T>(e);
	if (last) {
		newNode->link = last->link;
		last->list = newNode;
	}
	else {
		last = newNode;
		newNode->link = newNode;
	}
}