template <class E, class K>
int SeqSearch(E* a, const int n, const K& k) {
	int i;
	for (i = 0; i <= n && a[i] != k; i++);
	if (i > n) return 0;
	return i;
}