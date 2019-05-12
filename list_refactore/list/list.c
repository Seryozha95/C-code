#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print(node* list) {
  while (NULL != list) {
    printf("%p: -> %d ", (void*)list, list->data);
    list = list->next;
  }
  printf("-> NULL\n");
}

node* initialize(node* list, int n) {
  if (n < 1)  {
    return list;
  }
  while(n > 0) {
    node* temp = (node*) malloc(sizeof(node));
    temp->data = n;
    temp->next = list;
    list = temp;
    n--;
  }
  return list;
}

node* reverse(node* list) {
  node* reversed_list = NULL; 
  while(NULL != list) {
    node* temp = list;
    list = list->next;
    temp->next = reversed_list;
    reversed_list = temp;   
 }
 return reversed_list;
}

node* shuffle(node* list) {
  node* odd = NULL;
  node* odd_first =NULL;
  node* even = NULL;
  node* even_first = NULL;
  if (NULL == list || NULL == list->next) {
    return list;
  }
  odd_first = list;
  odd = list;
  list = list->next;
  even_first = list;
  even = list;
  list = list->next;
  while(NULL != list) {
    odd->next = list;
    odd = odd->next;
    list = list->next;
    even->next = list;
    even = even->next;
    list = list->next;
  }
  print(even_first);
  odd->next = even_first;
  return odd_first;
}

node* shuffleN(node* list, int n) {
  int i = 0;
  node * head = NULL;
  node** heads = (node**) malloc(n*sizeof(node));
  node** tails = (node**) malloc(n*sizeof(node));
  if (NULL == list || NULL == list->next || n < 2) {
    return list;
  }
  while(NULL != list) {
    if (heads[i] == NULL) {
      heads[i] = list;
    }
    if (tails[i] == NULL) {
      tails[i] = list;
    } else {
      tails[i]->next = list;
      tails[i] = tails[i]->next;
    }
    list = list->next;
    i++;
    if(i > n -1) {
			i = 0;
		}
  }
  i = 0;
	while (i < n) {
    if (NULL == tails[i]) {
      break;
    }
		tails[i]->next = heads[i+1];
		i++;
	}
  head = heads[0];
  free(heads);
  free(tails);
  return head;
}

node* delete(node * list) {
  while(NULL != list) {
    node* temp = list->next;
    free(list);
    list = temp;
  }
  return NULL;
}