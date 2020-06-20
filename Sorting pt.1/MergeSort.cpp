#include <crtdbg.h>
#include <corecrt_malloc.h>

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		sIdx++;
	}

	if (fIdx > mid) {		//오른쪽 집합에 남아있으면 쓸어담기
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);
}