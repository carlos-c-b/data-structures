#include "utils.h"
#include "RecursiveQuicksort.h"
#include "IterativeQuicksort.h"
#include <iostream>
#include <chrono>
#include <functional>
#include "AlgorithmComparison.h"
using namespace std;


int main(int argc, char *argv[]) {
	cout << "Size\t\tRecursive\tIterative" << endl;
	compareSortingAlgorithms(recursiveQuicksort, iterativeQuicksort, 10000);
	compareSortingAlgorithms(recursiveQuicksort, iterativeQuicksort, 100000);
	compareSortingAlgorithms(recursiveQuicksort, iterativeQuicksort, 500000);

}
