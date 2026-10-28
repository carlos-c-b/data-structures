#include <iostream>
using namespace std;

void error(string msg) {
	cout << msg << endl;
	abort();
}

template <class E>
class CircularQueue {
	private:
		int head, tail;
		int capacity;
		int size;
		E *array;
	public:
		// Capacity >= 0
		CircularQueue(int capacity = 0) {
			if(capacity < 0) {
				error("Error: capacity must be >= 0");
			}
			this->capacity = capacity;
			array = new int[capacity];
			head = tail = size = 0;
		}
		void put(E e) {

			if(capacity == size)
				duplicateCapacity();
			array[head] = e;
			head = (head+1) % capacity;
			size++;
		}
		E peek() const {
			if(size == 0)
				error("Error: empty queue");
			return array[tail];
		}
		E pop() {
			if(size == 0)
				error("Error: empty queue");
			E e = array[tail];
			tail = (tail+1) % capacity;
			size--;
			return e;
		}
		int getSize() const { return size; }
		void duplicateCapacity() {
			E *aux = new E[capacity*2];
			int k;

			// Since it is assumed array is full, we copy everything
			for(k = 0; k < capacity; k++) aux[k] = array[(k+tail) % capacity];

			capacity *= 2;
			array = aux;
			tail = 0;
			head = k;
		}
		void printQueue() const {
			cout << "Capacity: " << capacity << "\tSize: " << size << endl;
			if(tail < head) {
				for(int i = 0; i < capacity; i++) {
					if((i >= tail && i <= head-1)) {
						cout << " " << array[i];
					} else {
						cout << " .";
					}
				}
			} else if(tail > head){
				for(int i = 0; i < capacity; i++) {
					if((i >= head && i <= tail-1)) {
						cout << " .";
					} else {
						cout << " " << array[i];
					}
				}
			} else { // i.e. H==T, then queue is either empty or full
				for(int i = 0; i < capacity; i++) {
					if(size == 0)
						cout << " .";
					else
						cout << " " << array[i];
				}
			}
			cout << endl;
			for(int i = 0; i < capacity; i++) {
				if(i == head || i == tail)
					cout << " ^";
				else cout << "  ";
			}
			cout << endl;
			for(int i = 0; i < capacity; i++) {
				if(i == head && i == tail)
					cout << "H/T";
				else if(i == head)
					cout << " H";
				else if(i == tail)
					cout << " T";
				else cout << "  ";
			}
			cout << endl;
		}
};

template <class E>
int step(CircularQueue<E>& q) {
	cout << "1: put random number, 0: pop number: ";	
	int r;
	cin >> r;
	if(r == 1) {
		q.put(rand() % 10);
		q.printQueue();
	} else if(r == 0) {
		q.pop();
		q.printQueue();
	} else {
		cout << "Exit\n";
		return -1;
	}
	return 0;
}


int main(int argc, char **argv) {
	CircularQueue<int> q(5);
	int v;
	q.printQueue();
	do {
		v = step(q);
	} while(v == 0);
	
	return 0;
}
