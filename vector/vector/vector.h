#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 4

typedef struct vector
{
	int* items;
	int capacity;
	int length;
}
vector;

vector* vector_init();
void vector_free(vector *);
void add(vector* v, int value);
void insert(vector* v, int value, unsigned int index);
void delete(vector* v, unsigned int index);
int* get(vector* v, unsigned int index);
void reverseN(vector* v, int n);
void quick_sort(vector* v, int start, int end);
void swap(vector* v, int start, int end);
void resize(vector* v, int capacity);
void print(vector * v);
#endif
