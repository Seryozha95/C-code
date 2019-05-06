#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	node *list = NULL;
	list = initialize(list, 5);
	printf("Initialize\n");
	print(list);
	list = reverse(list);
	printf("Reversed version:\n");
	print(list);
	printf("Shuffled version:\n");
	list = shuffle(list);
	print(list);
	return 0;
}