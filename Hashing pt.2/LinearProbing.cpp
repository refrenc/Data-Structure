template <class K, class E>
pair<K, E>* LinearProbing <K, E>::Get(const K& k) {
	int i = h(k);
	int j;
	for (j = i; ht[k] && ht[j]->first != k;) {
		j = (j + 1) % b;
		if (j == i) return 0;
	}
	if (ht[j]->first == k)return ht[j];
	return 0;
}