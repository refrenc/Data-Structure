template <class T>
void LinkedStack<T>::Push(const T& e) {
	top = new ChainNode<T>(e, top);
}

template <class T>
void LinkedStack<T>::Pop() {
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	ChainNode<T>* delNode = top;
	top = top->link;
	delete delNode;
}