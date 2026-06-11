#include <iostream>
using namespace std;


struct Node {
	int id;
	int data;
	Node *next;
};

struct List {
	Node *first;
	Node *last;
	int size;
};

void initialize_list(List& l) {
	l = { NULL, NULL, 0 };
}


void insert_node(List& l, int data, int pos) {
	if(pos < 0) return;
	if(pos > l.size) pos = l.size;

	Node *n = (Node*) malloc(sizeof(Node));
	*n = { l.size+1, data, NULL };

	if(pos == l.size) {
		if(l.size > 0)
			l.last->next = n;
		l.last = n;
	}
	if (pos == 0) {
		n->next = l.first;
		l.first = n;
	} 

	if(pos != l.size && pos != 0){
		Node *next = l.first;
		for(int i = 0; i < pos-1; i++) next = next->next;
		Node *aux = next->next;
		next->next = n;
		n->next = aux;
	}

	l.size++;	
}

void insert_node(List& l, int data) {
	insert_node(l, data, l.size);
}

void remove_node(List& l, int pos) {
	if(pos >= l.size || pos < 0) return;

	if(pos == 0) {
		if(l.size > 0) l.first = l.first->next;
		else l.first = NULL;
	}
	if(pos == l.size-1) {
		if(l.size == 1) l.last = NULL;
		else {
			Node *new_last = l.first;
			for(int i = 0; i < l.size-2; i++) new_last = new_last->next;
			new_last->next = NULL;
			l.last = new_last;
		}
	}
	if(pos != 0 && pos != l.size-1) {
		Node *aux = l.first;
		for(int i = 0; i < pos-1; i++) aux = aux->next;
		aux->next = aux->next->next;	
	}

	l.size--;

}

// Returns position of node given its id or -1
int find_by_id(List& l, int id) {
	Node *aux = l.first;
	for(int i = 0; i < l.size; i++) {
		if(aux->id == id) return i;
		aux = aux->next;
	}
	return -1;
}

int find_by_data(List& l, int data) {
	Node *aux = l.first;
	for(int i = 0; i < l.size; i++) {
		if(aux->data == data) return i;
		aux = aux->next;
	}
	return -1;
}

void print_node(Node& b) {
	cout << "ID: " << b.id << "\nData: " << b.data << "\nNext_ID: " << b.next->id << '\n';
}

void print_list(List& l) {
	if(l.first == NULL) return;
	Node *n = l.first;
	int i = 0;
	while(n->next != NULL) {
		print_node(*n);
		n = n->next;
		cout << '\n';
	}
	cout << "ID: " << n->id << "\nData: " <<  n->data << "\nNext: NULL\n";
}

int main() {
	List l;
	initialize_list(l);
	insert_node(l, 10);
	insert_node(l, 20);
	insert_node(l, 30);
	insert_node(l, 40, 1);
	remove_node(l, 1);
	print_list(l);
}
