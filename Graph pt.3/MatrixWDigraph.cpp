class MatrixWDigraph {
public:
	void ShortestPath(const int n, const int v);	//Dijkstra algorithm > ���� ����ġ�� ���
	void BellmanFord(const int n, const int v);		//���� ����ġ ���, ���� ��� O(n^3), ���� ����Ʈ O(ne)
	void AllLengths(const int n);					//���� ����ġ�� ���� ��� �׷����� ��� �ֿ� ���� �ִ� ��� O(n^3)
private:
	int** length;
	int* dist;
	bool* s;		//���õ� ����
};

void MatrixWDigraph::ShortestPath(const int n, const int v) {
	for (int i = 0; i < n; i++) {
		s[i] = false;
		dist[i] = length[v][i];
	}	//�ʱ�ȭ
	s[v] = true;
	dist[v] = 0;

	for (int i = 0; i < n - 2; i++) {
		int u = Choose(n);		//s[w] = false �̰� dist[u] = min dist[w]�� �Ǵ� u ��ȯ
		s[u] = true;
		for (int w = 0; w < n; w++) {
			if (!s[w] && dist[u] + length[u][w] < dist[w])
				dist[w] = dist[u] + length[u][w];
		}
	}
}

void MatrixWDigraph::BellmanFord(const int n, const int v) {
	for (int i = 0; i < n; i++) dist[i] = length[v][i];	//�ʱ�ȭ

	for (int k = 0; k <= n; k++) {
		for (u != v && �ּ��� �ϳ��� ���� ������ ���� u)
			for (�׷����� �� <i, u>�� ����)
				if (dist[u] > dist[i] + length[i][u]) dist[u] = dist[i] + length[i][u];
	}
}