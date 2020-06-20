template <class T>
void LinkedQueue<T>::Push(const T& e) {
	if (IsEmpty()) front = rear = new ChainNode;
	else rear = rear->link = new ChainNode(e, 0);
}

template <class T>
void LinkedQueue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty. Cannot delete";
	ChainNode<T>* delNode = front;
	front = front->link;
	delete delNode;
}