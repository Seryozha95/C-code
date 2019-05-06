#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* initialize(node* list, int n) {
	while (n > 0) {
		node* temp = (node*) malloc(sizeof(node));
    temp->next = list;
    temp->data = n;
    list = temp;
    n--;
	}
	return list;  
}

node* reverse(node *list) {
	node* temp;
	node* reversed_list = NULL;

	while(list != NULL) {
		temp = list->next;
		list->next = reversed_list;
		reversed_list = list;
		list = temp;
	}
	return reversed_list;
}

node* shuffle(node* list) {
  if(list == NULL) {
    return list;
  }
  node* odd = NULL;
  node* even = NULL;
  node* odd_first = NULL;
  node* even_first = NULL;
  int i = 0;  
   while (list != NULL) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = list->data;
    temp->next = NULL;
    if (i == 0) {
      if (odd == NULL) {
        odd_first = temp;
      } else {
        odd->next = temp;
      }
      i = 1;
      odd = temp;
    } else {
      if (even == NULL) {
        even_first = temp;
      } else {
        even->next = temp;
      }
      i = 0;
      even = temp;
    }
		list = list->next;
	}
  odd->next = even_first;
  return odd_first;
}

void print(node* list) {
	while (list != NULL) {
		printf("%p: ->: %d ", list, list->data);
		list = list->next;
	}
	printf("%p:\n", list);
}