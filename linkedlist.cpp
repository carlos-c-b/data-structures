#include <iostream>
using namespace std;


struct Node {
	int id;
	int data;
	Node *next;
};

void print_node(Node& b) {
	cout << "ID: " << b.id << "\nData: " << b.data << "\nNext: " << b.next << '\n';
}

void print_list(Node& b) {
	Node *n = &b;
	int i = 0;
	while(n->next != NULL) {
		print_node(*n);
		n = n->next;
		cout << '\n';
	}
	cout << "ID: " << n->id << "\nData: " <<  n->data << "\nNext: NULL\n";
}

int main() {
	Node b1 = { 1, 10, NULL };
	Node b2 = { 2, 100, &b1 };
	Node b3 = { 3, 1000, &b2 };
	print_list(b3);
}
