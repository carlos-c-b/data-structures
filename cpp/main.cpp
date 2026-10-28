#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
	List<int> l;
	initialize_list(l);
	insert_node(l, 10);
	insert_node(l, 10);
	insert_node(l, 10);
	insert_node(l, 10);
	insert_node(l, 100, 2);
	print_list(l);
}
