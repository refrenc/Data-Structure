template <class T> class Tree;
template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
};

template <class T>
class Tree {
public:
	void Inorder();		//중위순회
	void Inorder(TreeNode<T>* currentNode);
	void Preorder();	//전위순회
	void Preorder(TreeNode<T>* currentNode);
	void Postorder();	//후위순회
	void Postorder(TreeNode<T>* currentNode);
private:
	TreeNode<T>* root;
};

template <class T>
void Tree<T>::Inorder() {
	Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::Preorder() {
	Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::Postorder() {
	Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}