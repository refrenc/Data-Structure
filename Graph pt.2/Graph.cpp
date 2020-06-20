#include <iostream>

class Graph {
public:
	virtual ~Graph() {}
	bool IsEmpty() const { return n == 0; };
	int NumberOfVertices() const { return n; };
	int NumberOfEdges() const { return e; };
	virtual int Degree(int u) const = 0;
	virtual bool ExixtsEdge(int u, int v) const = 0;
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdges(int u, int v) = 0;
	virtual void DeleteVertex(int v) = 0;
	virtual void DeleteEdge(int u, int v) = 0;

	virtual void DFS();
	virtual void DFS(const int v);
	virtual void BFS(int v);

	virtual void Components();
private:
	int n;
	int e;
	bool* visited;
};

void Graph::DFS() {			//인접 리스트 : O(V + E), 인접 행렬 : O(n^2)
	visited = new bool[n];
	std::fill(visited, visited + n, false);
	DFS(0);
	delete[] visited;
}

void Graph::DFS(const int v) {
	visited[v] = true;
	for (each vertex w adjacent to v)
		if (!visited[w]) DFS(w);
}

void Graph::BFS(int v) {	//O(n^2)
	visited = new bool[n];
	std::fill(visited, visited + n, false);
	visited[v] = true;
	Queue<int> q;
	q.Push(v);
	while (!q.IsEmpty()) {
		v = q.Front();
		q.Pop();
		for (all vertices w adjacent to v) {
			if (!visited[w]) {
				q.Push(w);
				visited[w] = true;
			}
		}
	}
	delete[] visited;
}

void Graph::Components() {
	visited = new bool[n];
	std::fill(visited, visited + n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			DFS(i);
			OutputNewComponent();
		}
	}
	delete[] visited;
}