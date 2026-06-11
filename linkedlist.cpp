#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


template <typename T>
class Node {
	private:
		int id;
		T elem;
		Node<T> *next;
	public:
		Node(int id, T elem, Node<T> *next) {
			this->id = id;
			this->elem = elem;
			this->next = next;
		}	

		int get_id() {
			return id;
		}

		Node* get_next() {
			return next;
		}

		void set_next(Node<T> *next) {
			this->next = next;
		}

		T get_elem() {
			return elem;
		}

		void print_node() {
			cout << "ID: " << id << "\nData: " << elem << "\nNext_ID: " << next->id << '\n';
		}
};

template <typename T>
class List {
	private:
		Node<T> *first;
		Node<T> *last;
		int size;


	public:
		List() {
			first = nullptr;
			last = nullptr;
			size = 0;
		}

		void insert_node(T elem, int pos) {
			if(pos < 0) return;
			if(pos > size) pos = size;

			Node<T> *n = new Node<T>(size+1, elem, NULL);

			if(pos == size) {
				if(size > 0)
					last->set_next(n);
				last = n;
			}
			if (pos == 0) {
				n->set_next(first);
				first = n;
			} 

			if(pos != size && pos != 0){
				Node<T> *next = first;
				for(int i = 0; i < pos-1; i++) next = next->get_next();
				Node<T> *aux = next->get_next();
				next->set_next(n);
				n->set_next(aux);
			}

			size++;	
		}

		void insert_node(T elem) {
			insert_node(elem, size);
		}

		void remove_node(int pos) {
			if(pos >= size || pos < 0) return;

			if(pos == 0) {
				if(size > 0) first = first->get_next();
				else first = NULL;
			}
			if(pos == size-1) {
				if(size == 1) last = NULL;
				else {
					Node<T> *new_last = first;
					for(int i = 0; i < size-2; i++) new_last = new_last->get_next();
					new_last->set_next(NULL);
					last = new_last;
				}
			}
			if(pos != 0 && pos != size-1) {
				Node<T> *aux = first;
				for(int i = 0; i < pos-1; i++) aux = aux->get_next();
				aux->set_next(aux->get_next()->get_next());
			}

			size--;
		}

		int find_by_id(int id) {
			Node<T> *aux = first;
			for(int i = 0; i < size; i++) {
				if(aux->id == id) return i;
				aux = aux->get_next();
			}
			return -1;		
		}

		int find_by_elem(T elem) {
			Node<T> *aux = first;
			for(int i = 0; i < size; i++) {
				if(aux->get_elem() == elem) return i;
				aux = aux->get_next();
			}
			return -1;
		}

		void print_list() {
			if(first == NULL) return;
			Node<T> *n = first;
			int i = 0;
			while(n->get_next() != NULL) {
				n->print_node();
				n = n->get_next();
				cout << '\n';
			}
			cout << "ID: " << n->get_id() << "\nData: " <<  n->get_elem() << "\nNext: NULL\n";
		}

		int get_size() {
			return size;
		}
};



int main() {
	List<int> *l = new List<int>();
	l->insert_node(10);
	l->insert_node(10);
	l->insert_node(10);
	l->insert_node(10);
	l->insert_node(10, 1);
	l->remove_node(l->get_size());
	l->print_list();
}

#endif
