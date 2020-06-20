#define BUCKET_NUM 10

void Radixsort(int arr[], int num, int maxLen) {
	Queue buckets[BUCKET_NUM];
	int bi, pos, di, divfac = 1, radix;

	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	for (pos = 0; pos < maxLen; pos++) {
		for (di = 0; di < num; di++) {
			radix = (arr[di] / divfac) % 10;		//n��° �ڸ� ���� ����
			Enqueue(&buckets[radix], arr[di]);		//��Ŷ�� ����
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			while (!QIsEmpty(&buckets[bi]))			//���� ������ ������ �ٽ� arr�� ����
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac * 10;
	}
}