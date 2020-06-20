template <class T>
class LinkedGraph {
private:
	Chain<int>* adjList;
	int n;
	int e;
public:
	LinkedGraph(const int vertices = 0) : n(vertices), e(0) {
		adjLists = new Chain<int>[n];
	}
};