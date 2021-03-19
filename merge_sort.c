/*
 * Sooyoung Jeon
 * Merge Sort
 */

#include <stdio.h>

int number = 8;

int size;
int sorted[8];
int count = 0;

void merge(int a[], int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	int k = m;
	int t;

	/* Insert by the smalleset number */
	while (i <= mid && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	/* Insert the rest of the data */
	if (i > mid) {
		for (t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
		for (t = i; t <= mid; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	/* Insert the sorted array */
	for (t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void merge_sort(int a[], int m, int n) {
	/* If the size is not 1, preceed the sorting */
	if (m < n) {
		int mid = (m + n) / 2;
		merge_sort(a, m, mid);
		merge_sort(a, mid + 1, n);
		merge(a, m, mid, n);
	}
}

int main(void) {
	int i;
	int array[] = {7, 6, 5, 8, 3, 5, 9, 1};
	merge_sort(array, 0, number - 1);
	for (i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
