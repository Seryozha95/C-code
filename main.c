#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	node *list = NULL;
	list = initialize(list, 9);
	printf("Initialize\n");
	print(list);
	list = reverse(list);
	printf("Reversed version:\n");
	print(list);
	printf("Shuffled version:\n");
	list = shuffle(list);
	print(list);
	printf("Shuffled N version:\n");
	list = shuffleN(list, 3);
	print(list);
	printf("Reverse N version:\n");
	list = reverseN(list, 3);
	print(list);
	return 0;
}