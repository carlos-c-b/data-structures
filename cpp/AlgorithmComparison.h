#include "utils.h"
#include "RecursiveQuicksort.h"
#include "IterativeQuicksort.h"
#include <iostream>
#include <chrono>
#include <functional>
using namespace std;

auto timeSortingAlgorithm(function<void(int*,int)> alg, int size) {
	int *array = new int[size];
	fillArray(array, size);

	auto start =chrono::high_resolution_clock::now();

	alg(array, size);

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds> (end - start);
	return duration;
}


void compareSortingAlgorithms(function<void(int*,int)> alg1, function<void(int*,int)> alg2, int size) {
	cout << size << "\t\t";
	auto duration = timeSortingAlgorithm(alg1, size);
	cout << duration.count() << "\t\t";
	auto duration2 = timeSortingAlgorithm(alg2, size);
	cout << duration2.count() << endl;
}
