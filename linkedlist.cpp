#include <iostream>
using namespace std;


template <typename T>
struct Node {
	int id;
	T data;
	Node<T> *next;
};

template <typename T>
struct List {
	Node<T> *first;
	Node<T> *last;
	int size;
};

template <typename T>
void initialize_list(List<T>& l) {
	l = { NULL, NULL, 0 };
}


template <typename T>
void insert_node(List<T>& l, int data, int pos) {
	if(pos < 0) return;
	if(pos > l.size) pos = l.size;

	Node<T> *n = (Node<T>*) malloc(sizeof(Node<T>));
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
		Node<T> *next = l.first;
		for(int i = 0; i < pos-1; i++) next = next->next;
		Node<T> *aux = next->next;
		next->next = n;
		n->next = aux;
	}

	l.size++;	
}

template <typename T>
void insert_node(List<T>& l, int data) {
	insert_node(l, data, l.size);
}

template <typename T>
void remove_node(List<T>& l, int pos) {
	if(pos >= l.size || pos < 0) return;

	if(pos == 0) {
		if(l.size > 0) l.first = l.first->next;
		else l.first = NULL;
	}
	if(pos == l.size-1) {
		if(l.size == 1) l.last = NULL;
		else {
			Node<T> *new_last = l.first;
			for(int i = 0; i < l.size-2; i++) new_last = new_last->next;
			new_last->next = NULL;
			l.last = new_last;
		}
	}
	if(pos != 0 && pos != l.size-1) {
		Node<T> *aux = l.first;
		for(int i = 0; i < pos-1; i++) aux = aux->next;
		aux->next = aux->next->next;	
	}

	l.size--;

}

// Returns position of node given its id or -1
template <typename T>
int find_by_id(List<T>& l, int id) {
	Node<T> *aux = l.first;
	for(int i = 0; i < l.size; i++) {
		if(aux->id == id) return i;
		aux = aux->next;
	}
	return -1;
}

template <typename T>
int find_by_data(List<T>& l, int data) {
	Node<T> *aux = l.first;
	for(int i = 0; i < l.size; i++) {
		if(aux->data == data) return i;
		aux = aux->next;
	}
	return -1;
}

template <typename T>
void print_node(Node<T>& b) {
	cout << "ID: " << b.id << "\nData: " << b.data << "\nNext_ID: " << b.next->id << '\n';
}

template <typename T>
void print_list(List<T>& l) {
	if(l.first == NULL) return;
	Node<T> *n = l.first;
	int i = 0;
	while(n->next != NULL) {
		print_node(*n);
		n = n->next;
		cout << '\n';
	}
	cout << "ID: " << n->id << "\nData: " <<  n->data << "\nNext: NULL\n";
}

int main() {
	List<int> l;
	initialize_list(l);
	insert_node(l, 10);
	insert_node(l, 20);
	insert_node(l, 30);
	insert_node(l, 40, 1);
	remove_node(l, 1);
	print_list(l);
}
