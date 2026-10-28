#include <stdio.h>
#include <stdlib.h>

typedef enum { INT, STRING } Type;

typedef struct {
	void *array;
	int size;
}	hash_table;

hash_table* new_hash_table(Type t, int size) {
	hash_table *h = malloc(sizeof(hash_table));
	h->size = size;
	switch(t) {
		case STRING:
			h->array=(char *)malloc(size);
		default:
			h->array=(int *)malloc(sizeof(int)*size);	// This should be a pointer to char pointers
	}
	return h;
}

int main() {
	hash_table *h = new_hash_table(STRING, 100);
}
