#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void print(vector* v) {
	int i;
	for (i = 0; i< v->length; i++) {
		printf("[%d] -> : %d\n", i, v->items[i]);
	}
}

vector* vector_init() {
	vector *v = (vector *) malloc(sizeof(vector));
	v->capacity = VECTOR_INIT_CAPACITY;
	v->length = 0;
	v->items = calloc(v->capacity, sizeof(int));
	return v;
}

void vector_free(vector* v) {
	free(v->items);
}

int* get(vector* v, unsigned int index) {
	if(index < v->length) {
		return (v->items+index);
	}
	return NULL;
}

void delete(vector* v, unsigned int index) {
	int i = index;
	if (v->length == 0 || index >= v->length) {
		return;
	}
	for(; i < v->length; i++) {
		v->items[i] = v->items[i+1];
	}
	--v->length;
	if (v->length > 0 && v->length == v->capacity / 4) {
		resize(v, v->capacity / 2);
	}
}

void add(vector* v, int value) {
	if (v->length == v->capacity) {
		resize(v, v->capacity * 2);
	}
	v->items[v->length] = value;
	++v->length;
}

void insert(vector* v, int value, unsigned int index) {
	int i = v->length;
	if (index >= v->length) {
		return;
	}
	if (v->length == v->capacity) {
		resize(v, v->capacity * 2);
	}
	for(; i > index; i--) {
		v->items[i] = v->items[i-1];
	}
	v->items[i] = value;
	++v->length;
}

void resize(vector* v, int capacity) {
	int* items = realloc(v->items, capacity * sizeof(v->items));
	if(items) {
		v->items = items;
		v->capacity = capacity;
	}
}

void reverseN(vector* v, int n) {
	int i = 0;
	int position = 0;
	int buff_index = n - 1;
	while(i < n/2 && position < v->length) {
		int buff = v->items[buff_index];
		v->items[buff_index] = v->items[position];
		v->items[position] = buff;
		position++;
		buff_index--;
		if (++i >= n/2 && position < v->length - 1) {
			position += n - i;
			buff_index =  position + (n - i) >= v->length -1 ? v->length -1 :  position + n - 1;
			i = 0;
		}
	}
}

