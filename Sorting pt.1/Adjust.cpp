/*최대 힙으로 재조정*/

template <class T>
void Adjust(T* a, const int root, const int n) {
	T e = a[root];

	for (int j = 2 * root; j <= n; j *= 2) {
		if (j < n && a[j] < aa[j + 1]) j++;		//자식 노드 중 큰걸로 가
		if (e >= a[j]) break;
		a[j / 2] = a[j];
	}
	a[j / 2] = e;
}

template <class T>
void HeapSort(T* a, const int n) {
	for (int i = n / 2; i >= 1; i--)
		Adjust(a, i, n);

	for (int i = n - 1; i >= 1; i--) {
		swap(a[1], a[i + 1]);		//루트와 맨 마지막 교환
		Adjust(a, 1, i);
	}
}