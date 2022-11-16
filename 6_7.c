#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100001

typedef struct Node_s{
  struct Node_s *prev, *next;
  void *value;
} Node;

typedef Node List;

void initList(List *list){
  list->next = list;
  list->prev = list;
  list->value = NULL;
}

Node *addAfter(Node *node, void *ptr){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = ptr;
  newNode->prev = node;
  newNode->next = node->next;
  node->next->prev = newNode;
  node->next = newNode;
  return newNode;
}

Node *addBefore(Node *node, void *ptr){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = ptr;
  newNode->next = node;
  newNode->prev = node->prev;
  node->prev->next = newNode;
  node->prev = newNode;
  return newNode;
}

void *erase(Node *node){
  void *res = node->value;
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
  return res;
}

int main(){
  List head;
  Node *arr[N];
  int value[N];
  int t, q, tmp, index, count;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    count = 0;
    initList(&head);
    scanf("%d", &q);
    for(int j = 0; j < q; j++){
      scanf("%d %d", &tmp, &index);
      switch (tmp) {
        case 0:
          erase(arr[index]);
          break;
        case 1:
          scanf("%d", &value[count]);

          if (index == -1){
            arr[count] = addAfter(&head, &value[count]);
          }
          else{
            arr[count] = addAfter(arr[index], &value[count]);
          }
          count++;
          break;
        case -1:
          scanf("%d", &value[count]);

          if (index == -1){
            arr[count] = addBefore(&head, &value[count]);
          }
          else{
            arr[count] = addBefore(arr[index], &value[count]);
          }
          count++;
          break;
      }
    }
    Node *p;
    p = &head;
    int* res;
    while(p->next != &head){
      res = (int*)(p->next)->value;
      printf("%d\n", *res);
      p = p->next;
      if(p->prev != &head){
        free(p->prev);
      }
    }
    free(p);
    printf("===\n");
  }
  return 0;
}
