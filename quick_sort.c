/* 
 * Sooyoung Jeon
 * Quick Sort 
 */

#include <stdio.h>

int number = 10;
int data[] = {1, 10, 3, 8, 7, 6, 4, 5, 2, 9};

void show() {
	int i;
	for (i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
}

void quick_sort(int* data, int start, int end) {
	
	int key, i, j, temp;

	/* Return if the data has only a value */
	if (start >= end) {
		return;
	}

	key = start; /* Key is the first value */
	i = start + 1; 
	j = end;

	/* Loop until i and j cross over each other */
	while (i <= j) {
		/* Loop until the value is larger than key */
		while (i <= end && data[i] <= data[key]) {
			i++;
		}

		/* Loop until the value is smaller than key */
		while (j > start && data[j] >= data[key]) {
			j--;
		}

		/* Swap the key and current value if i and j cross over each other
		 * If now, swap i and j */
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		} else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	/* Recurse the front and back part of the remaning data */
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main(void) {
	quick_sort(data, 0, number - 1);
	show();
	return 0;
}
