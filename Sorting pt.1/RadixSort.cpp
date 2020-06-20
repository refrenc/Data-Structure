#define BUCKET_NUM 10

void Radixsort(int arr[], int num, int maxLen) {
	Queue buckets[BUCKET_NUM];
	int bi, pos, di, divfac = 1, radix;

	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	for (pos = 0; pos < maxLen; pos++) {
		for (di = 0; di < num; di++) {
			radix = (arr[di] / divfac) % 10;		//n번째 자리 숫자 추출
			Enqueue(&buckets[radix], arr[di]);		//버킷에 저장
		}

		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++) {
			while (!QIsEmpty(&buckets[bi]))			//저장 순서로 꺼내서 다시 arr에 저장
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac * 10;
	}
}