#include <stdio.h>
#include <stdlib.h>
#include "vector/vector.h"

int main() {
	vector* v = vector_init();
	int i = 0;
	for (; i <= 10; i++) {
		add(v, i);
	}
	printf("Start\n");
	insert(v, 1211, 1);
	delete(v, 0);
	add(v, 101001);
	print(v);
	i = *get(v, 0);
	printf("%s: -> %d\n", "Item is" , i);
	printf("Reverse\n");
	reverseN(v, 2);
	print(v);
	printf("Sort\n");
	quick_sort(v, 0, 20);
	print(v);
	return 0;
}
