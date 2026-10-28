#pragma once
#include <iostream>

extern void fillArray(int *array, const int size) {
	for(int i = 0; i < size; i++) array[i] = rand() % 100;
}
extern void printArray(int *array, const int size) {
	for(int i = 0; i < size; i++) std::cout << array[i] << " ";
	std::cout << std::endl;
}

extern void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

extern void error(std::string msg) {
	std::cout << msg << std::endl;
	abort();
}
