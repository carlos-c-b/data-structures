#include "Node.h"
#include <iostream>
using namespace std;

/*
 * Each iteration is owned by some node, which contains the full state
 * needed to run the algorithm in that iteration: i.e., start, finale, and pivot
 * This is actually pretty inefficient, as many memory allocations happen
 */


int iterativeQuicksortAlg(int *array, int s, int f) {
	int i, j;
	i = s-1; j = s;
	for(j; j < f-1; j++)
		if(array[j] <= array[f-1]) swap(&array[++i], &array[j]);
	swap(&array[++i], &array[f-1]);	// Swap pivot
	return i;	// Return pivot position
	
}

void iterativeQuicksort_(int *array, int s, int f) {
	// We create root node
	int pv = iterativeQuicksortAlg(array, s, f);
	Node *activeNode = new Node(s, f, pv);
	// state[0] = start
	// state[1] = finale
	// state[2] = pivot
	int *state, n_pv;

	while(activeNode != nullptr) {
		// We load context
		state = activeNode->getState();
		s = state[0];
		f = state[1];
		pv = state[2];

		// We first go left, if possible
		if(s < pv-1 && !activeNode->hasLeftChild()) {
			n_pv = iterativeQuicksortAlg(array, s, pv);
			// Create left child
			Node *leftChild = new Node(s, pv, n_pv);
			activeNode->setLeftChild(*leftChild);	// Then, leftChild.getParent() == activeNode
			activeNode = leftChild;
			continue;	// We hand control to left child, to explore left branch
		}
		// If it's not possible to continue exploring left branch, we go right if possible
		else if(pv+1 < f-1 && !activeNode->hasRightChild()) {
			n_pv = iterativeQuicksortAlg(array, pv+1, f);
			// Create right child
			Node *rightChild = new Node(pv+1, f, n_pv);
			activeNode->setRightChild(*rightChild);	// Then, rightChild.getParent() == activeNode
			activeNode = rightChild;
			continue;	// We hand control to right child, to explore right branch
		}
		// If it's not possible to go either way, we return control to parent node
		else {
			activeNode = activeNode->getParent();
		}
	}
}

extern void iterativeQuicksort(int *array, int size) {
	iterativeQuicksort_(array, 0, size);
}


/* int main() { */
/* 	const int size = 20; */
/* 	int *array = new int[size]; */
/* 	fillArray(array, size); */

/* 	iterativeQuicksort(array, size); */

/* 	printArray(array, size); */

/* 	return 0; */
/* } */

