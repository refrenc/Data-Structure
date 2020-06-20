class MatrixWDigraph {
public:
	void ShortestPath(const int n, const int v);	//Dijkstra algorithm > 양의 가중치만 허용
	void BellmanFord(const int n, const int v);		//음의 가중치 허용, 인접 행렬 O(n^3), 인접 리스트 O(ne)
	void AllLengths(const int n);					//음의 가중치를 갖는 모든 그래프의 모든 쌍에 대한 최단 경로 O(n^3)
private:
	int** length;
	int* dist;
	bool* s;		//선택된 정렬
};

void MatrixWDigraph::ShortestPath(const int n, const int v) {
	for (int i = 0; i < n; i++) {
		s[i] = false;
		dist[i] = length[v][i];
	}	//초기화
	s[v] = true;
	dist[v] = 0;

	for (int i = 0; i < n - 2; i++) {
		int u = Choose(n);		//s[w] = false 이고 dist[u] = min dist[w]가 되는 u 반환
		s[u] = true;
		for (int w = 0; w < n; w++) {
			if (!s[w] && dist[u] + length[u][w] < dist[w])
				dist[w] = dist[u] + length[u][w];
		}
	}
}

void MatrixWDigraph::BellmanFord(const int n, const int v) {
	for (int i = 0; i < n; i++) dist[i] = length[v][i];	//초기화

	for (int k = 0; k <= n; k++) {
		for (u != v && 최소한 하나의 진입 간선을 갖는 u)
			for (그래프의 각 <i, u>에 대해)
				if (dist[u] > dist[i] + length[i][u]) dist[u] = dist[i] + length[i][u];
	}
}