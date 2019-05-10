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

node* shuffleN(node* list, int n) {
	if(list == NULL) {
		return list;
	}
	node** new_array = (node**) malloc(n*sizeof(node));
	node** first_points = (node**) malloc(n*sizeof(node));
	int i = 0;
	while (list != NULL) {
		node* temp = (node*) malloc(sizeof(node));
		temp->data = list->data;
		temp->next = NULL;
		if (new_array[i] == NULL) {
			first_points[i] = temp;
		} else {
			new_array[i]->next = temp;
		}
		new_array[i] = temp;
		list = list->next;
		i++;
		if(i > n -1) {
			i = 0;
		}
	}
	i = 0;
	while (i < n) {
		new_array[i]->next = first_points[i+1];
		i++;
	}
	return first_points[0];
}

node* reverseNRecursive(node* list, int n) {
	if(list == NULL) {
		return list;
	} 
	node* current = list; 
	node* temp = NULL; 
	node* reversed_list = NULL; 
	int i = 0;    
	while (current != NULL && i < n) 
	{ 
		temp  = current->next; 
		current->next = reversed_list; 
		reversed_list = current; 
		current = temp; 
		i++; 
	} 
	if (temp !=  NULL){
		list->next = reverseNRecursive(temp, n);
	} 
	return reversed_list; 
}

node* reverseN(node* list, int n) {
	if(n < 2 || list == NULL) {
		return list;
	}
	node* temp = NULL;
	node* reversed_list = NULL; 
	node* firstHead = NULL;
	node* head = NULL;
	node* end = NULL;
	node* lastEnd = NULL;
	int i = 1;  
	int isFirstTime = 1;
	while (NULL != list) {
		if (i == 1) {
			lastEnd = end;
			end = list;
			reversed_list = list;
			list = list->next;
		} else {
			if (i == n) {
				if(isFirstTime) {
					firstHead = list;
					isFirstTime = 0;
				}
				head = list;
				if(lastEnd != NULL) {
					lastEnd->next = head;
				}
				i = 0;
			}
			temp = list->next;
			list->next = reversed_list;
			reversed_list = list;
			list = temp;
		}
		i++;
	}
	end->next = NULL;
	if(NULL == firstHead) {
		return reversed_list;
	}
	if(i != 1) {
		lastEnd->next = reversed_list;
	}
	return firstHead;
}

void print(node* list) {
	while (list != NULL) {
		printf("%p: ->: %d ", list, list->data);
		list = list->next;
	}
	printf("%p:\n", list);
}
