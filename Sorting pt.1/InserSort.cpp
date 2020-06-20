void InserSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];	//정렬 대상

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)		//비교 대상 한칸 뒤로 밀기
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}