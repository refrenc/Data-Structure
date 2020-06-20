template <class T>
void Merge(T* initList, T* mergedList, const int l, const int m, const int n) {
	for (int i1 = 1, iResult = 1, i2 = m + 1; i1 <= m && i2 <= n; iResult++) {
		if (initList[i1] <= initList[i1]) {
			mergedList[iResult] = initList[i1];
			i1++;
		}
		else {
			mergedList[iResult] = initList[i2];
			i2++;
		}
	}

	copy(initList + i1, initList + m + 1, mergedList + iResult);
	copy(initList + i2, initList + n + 1, mergedList + iResult);
}