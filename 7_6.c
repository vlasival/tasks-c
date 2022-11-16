#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int data;
  struct List *next;
} List;

int main(){
  List *head;
  List *tmp;
  int n, k;
  head = (List*)malloc(sizeof(List));
  head->data = 1;
  tmp = head;

  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; i++){
    List *p = (List*)malloc(sizeof(List));
    p->data = i;
    tmp->next = p;
    tmp = p;
  }
  tmp->next = head;

  while (head->next != head){
    for (int i = 1; i < k - 1; i++){
      head = head->next;
    }
    List *t = head->next;
    head->next = t->next;
    printf("%d\n", t->data);
    free(t);
    head = head->next;
  }

  printf("%d\n", head->data);
  free(head);
}
