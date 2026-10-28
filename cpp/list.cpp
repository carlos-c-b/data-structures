#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


template <typename T>
class Node {
	protected:
		int id;
		T elem;
		Node<T> *next;
	public:
		Node(int id, T elem, Node<T> &next) {
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

		void set_next(Node<T> &next) {
			this->next = next;
		}

		T get_elem() {
			return elem;
		}

		void set_elem(T elem) {
			this->elem = elem;
		}

		void print_node() {
			cout << "ID: " << id << "\nData: " << elem << "\nNext_ID: " << next->id << '\n';
		}
};

template <typename T>
class List {
	protected:
		Node<T> *first;
		Node<T> *last;
		int size;


	public:
		List() {
			first = nullptr;
			last = nullptr;
			size = 0;
		}

		virtual void insert_node(T elem, int pos) {
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

		virtual void insert_node(T elem) {
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

		// Returns 0 if successful, -1 otherwise
		int modify_node(T elem, int pos) {
			if(pos >= size) return -1;
			Node<T> *aux = first;
			for(int i = 0; i < pos; i++) aux = aux->get_next();
			aux->set_elem(elem);
			return 0;
		}

		void print_list() {
			if(first == NULL) return;
			Node<T> *n = first;
			for(int i = 0; i < size; i++) {
				n->print_node();
				n = n->get_next();
				cout << '\n';
			}
		}

		int get_size() {
			return size;
		}
};


template <typename T>
class CircularList : public List<T> {
	public:
		void insert_node(T elem, int pos) override {
			if(pos > this->size) pos = this->size;

			if(pos < this->size) return List<T>::insert_node(elem, pos);

			Node<T> *new_node = new Node<T>((this->size)+1, elem, NULL);

			if(this->size == 0) {
				this->first = new_node;
				this->last = new_node;
				this->first->set_next(this->last);
				this->last->set_next(this->first);
			} else {
				this->last->set_next(new_node);
				new_node->set_next(this->first);
				this->last = new_node;
			}

			this->size++;

		}

		void insert_node(T elem) {
			insert_node(elem, this->size);
		}


};

template <typename T>
class WeightedList : {
	public:
		Node *start;
		int size;

		void insert_node(T elem, int cost) {

		}

}


int main() {
	CircularList<int> *l = new CircularList<int>();
	l->insert_node(10);
	l->insert_node(10);
	l->insert_node(10);
	l->insert_node(10);
	l->print_list();
}

#endif
