void InserSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];	//���� ���

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)		//�� ��� ��ĭ �ڷ� �б�
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}