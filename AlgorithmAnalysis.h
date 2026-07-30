/* Library for testing algorithm performance */
#include <iostream>
#include <functional>
#include <chrono>
#pragma once
#include "utils.h"
using namespace std;

auto execution(function<void (int*, int)> f, int n) {
	int *array = new int[n];
	fillArray(array, n);
	auto t1 = chrono::high_resolution_clock::now();
	f(array, n);
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1);
	return duration.count();
}

void showTimeTable(function<void(int*, int)> f, string algName, int initialN, int finalN, int step) {
	cout << "Time in milliseconds" << endl;
	cout << "N\t\t" << algName << endl;
	int n = initialN;
	while(n <= finalN) {
		cout << n << "\t\t" << execution(f, n) << endl;;
		n += step;
	}

}
