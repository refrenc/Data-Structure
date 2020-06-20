template <class T>
class BinaryTree {
public:
	BinaryTree();
	bool IsEmpty();
	BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);
	BinaryTree<T> LeftSubtree();
	BinaryTree<T> RightSubtree();
	T RootData();
};