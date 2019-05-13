#include <stdio.h>
#include <stdlib.h>
#include "./list/list.h"

int main() {
  node* list = NULL;
  list = initialize(list, 6);
  printf("Start\n");
  print(list);
  printf("Reverse\n");
  list = shuffleN(list, 2);
  print(list);
  list = delete(list);
  printf("Delete\n");
  print(list);
  return 0;
}