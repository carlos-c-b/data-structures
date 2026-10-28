#include <iostream>
#include <cstdlib>


int recursiveQuicksortAlg(int *array, int s, int f) {
	int i = s-1; int j = s;
	for(j; j < f-1; j++)
		if(array[j] <= array[f-1])
			swap(&array[++i], &array[j]);
	swap(&array[++i], &array[f-1]);
	return i;
}

void recursiveQuicksort_(int *array, int s, int f) {
	if(s >= f-1) return;

	int pv = recursiveQuicksortAlg(array, s, f);

	recursiveQuicksort_(array, s, pv);
	recursiveQuicksort_(array, pv+1, f);
}

extern void recursiveQuicksort(int *array, int size) {
	recursiveQuicksort_(array, 0, size);
}


/* int main(int argc, char *argv[]) { */
/* 	if(argc < 2) */
/* 		error("Error: array size needed"); */
/* 	const int size = std::atoi(argv[1]); */
/* 	int *array = new int[size]; */
/* 	fillArray(array, size); */

/* 	recursiveQuicksort(array, size); */

/* 	printArray(array, size); */

/* } */
