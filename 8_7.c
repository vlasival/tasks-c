#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
  double value;
  struct Node *prev, *next;
} Node;
//создаёт пустой список
//возвращает указатель на value в голове списка (вспом. узел)
double *initList(){
  Node* head = (Node*)malloc(sizeof(Node));
  head->next = head;
  head->prev = head;
  return (&head->value);
}

//полностью освобождает память списка
//принимает указатель на value голове списка (вспом. узел)
void freeList(double *head){
  Node *tmp, *save;
  tmp = (Node*)head;
  while(tmp->next != (Node*)head){
    save = tmp;
    tmp = tmp->next;
    free(save);
  }
  free(tmp);
}

//определяет следующий элемент после заданного
//(для вспом. узла возвращает первый элемент)
double *getNext(double* curr){
  Node *tmp = (Node*)curr;
  return (&tmp->next->value);
}

//определяет предыдущий элемент перед заданным
//(для вспом. узла возвращает последний элемент)
double *getPrev(double* curr){
  Node *tmp = (Node*)curr;
  return (&tmp->prev->value);
}

//создаёт и вставляет узел со значением newval сразу после узла where
double *addAfter(double* where, double newval){
  Node *tmp = (Node*)where;
  Node *new = (Node*)malloc(sizeof(Node));
  new->value = newval;
  new->prev = tmp;
  new->next = tmp->next;
  tmp->next->prev = new;
  tmp->next = new;
  return ((double*)new);
}

//создаёт и вставляет узел со значением newval сразу перед узлом where
double *addBefore(double* where, double newval){
  Node *tmp = (Node*)where;
  Node *new = (Node*)malloc(sizeof(Node));
  new->value = newval;
  new->next = tmp;
  new->prev = tmp->prev;
  tmp->prev->next = new;
  tmp->prev = new;
  return ((double*)new);
}

//удаляет и освобождает заданный узел
void erase(double* what){
  Node *tmp = (Node*)what;
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  printf("%0.3lf\n", tmp->value);
  free(tmp);
}

void printList(Node* head){
  Node *tmp;
  tmp = head;
  while(tmp->next != head){
    tmp = tmp->next;
    printf("%0.3lf\n", tmp->value);
  }
}

int main(){
  int t, q, cmd, index, count = 1;
  double data;
  double *array[100001];
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    double* list = initList();
    array[0] = list;
    scanf("%d", &q);
    for(int j = 0; j < q; j++){
      scanf("%d", &cmd);
      scanf("%d", &index);
      index++;
      switch (cmd) {
        case 0:
          erase(array[index]);
          break;
        case 1:
          scanf("%lf", &data);
          array[count++] = addAfter(array[index], data);
          break;
        case -1:
          scanf("%lf", &data);
          array[count++] = addBefore(array[index], data);
          break;
      }
    }
    printf("===\n");
    printList((Node*)list);
    printf("===\n");
    freeList(list);
    count = 1;
  }

  return 0;
}
