#include <stdio.h>
#include <stdlib.h>

typedef void (*callback)(void *ctx, int *value);

typedef struct Node_s{
  int data;
  struct Node_s *next;
} Node;

Node* addtoend(Node *list, int elem){
  Node *new = malloc(sizeof(Node));
  new->data = elem;
  new->next = 0;
  list->next = new;
  return new;
}

void sumChet(void *ctx, int *n){
  int *tmp = ctx;
  if ((*n) % 2 == 0){
    *tmp += (*n);
  }
}

void arrayForeach(void *ctx, callback func, int *arr, int n){
  for (int i = 0; i < n; i++){
    func(ctx, &arr[i]);
  }
}

void listForeach(void *ctx, callback func, Node *head){
  Node *tmp;
  while (head->next != 0) {
    tmp = head;
    func(ctx, &head->next->data);
    head = head->next;
    free(tmp);
  }
  free(head);
}

int main(){
  int n, tmp;
  int ctx = 0;
  scanf("%d", &n);
  Node *head = malloc(sizeof(Node));
  head->next = 0;
  Node *end = head;
  int *arr = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &tmp);
    arr[i] = tmp;
    end = addtoend(end, tmp);
  }
  arrayForeach((void*)(&ctx), sumChet, arr, n);
  printf("%d ", ctx);
  free(arr);
  ctx = 0;
  listForeach((void*)(&ctx), sumChet, head);
  printf("%d\n", ctx);
}
