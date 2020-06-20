#include <stdio.h>

void SelSort(int arr[], int n) {
	int i, j;
	int minIdx;
	int temp;

	for (i = 0; i < n - 1; i++) {
		minIdx = i;
		for (j = 0 + 1; j < n; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
	}

	/*±³È¯*/
	temp = arr[i];
	arr[i] = arr[minIdx];
	arr[minIdx] = temp;
}

int main(void) {
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	SelSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}