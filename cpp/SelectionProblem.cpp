#include <iostream>
#include "AlgorithmAnalysis.h"
#include "utils.h"

int quicksort_(int *array, int s, int f) {
	int i = s-1; int j = s;
	for(j; j < f-1; j++)
		if(array[j] <= array[f-1]) swap(&array[++i], &array[j]);
	swap(&array[++i], &array[f-1]);
	return i;
}

void quicksort(int *array, int s, int f) {
	if(s >= f-1) return;

	int pv = quicksort_(array, s, f);

	quicksort(array, s, pv);
	quicksort(array, pv+1, f);
}

void quicksort(int *array, int size) {
	quicksort(array, 0, size);
}

// Select k-biggest element of the array
int select(int *array, int size, int k) {
	quicksort(array, size);
	return array[k];
}

// Select k-biggest element of the array
int selectFixed(int *array, int size) {
	quicksort(array, size);
	return array[size/2];
}

int main() {
	showTimeTable([](int* arr, int n) { selectFixed(arr, n); }, "Selection Algorithm (Quicksort)",  10000, 100000, 10000);
	return 0;
}
