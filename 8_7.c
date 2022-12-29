#include <stdio.h>
#include <stdlib.h>


typedef struct Node_s {
  struct Node_s *prev, *next;
  double value;
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
  Node *tmp, *save, *golova;
  tmp = (Node*)((long long)head - sizeof(Node*) * 2);
  golova = tmp;
  while(tmp->next != golova){
    save = tmp;
    tmp = tmp->next;
    free(save);
  }
  free(tmp);
}

//определяет следующий элемент после заданного
//(для вспом. узла возвращает первый элемент)
double *getNext(double* curr){
  Node *tmp = (Node*)((long long)curr - sizeof(Node*) * 2);
  return (&tmp->next->value);
}

//определяет предыдущий элемент перед заданным
//(для вспом. узла возвращает последний элемент)
double *getPrev(double* curr){
  Node *tmp = (Node*)((long long)curr - sizeof(Node*) * 2);
  return (&tmp->prev->value);
}

//создаёт и вставляет узел со значением newval сразу после узла where
double *addAfter(double* where, double newval){
  Node *tmp = (Node*)((long long)where - sizeof(Node*) * 2);
  Node *new = (Node*)malloc(sizeof(Node));
  new->value = newval;
  new->prev = tmp;
  new->next = tmp->next;
  tmp->next->prev = new;
  tmp->next = new;
  return (&new->value);
}

//создаёт и вставляет узел со значением newval сразу перед узлом where
double *addBefore(double* where, double newval){
  Node *tmp = (Node*)((long long)where - sizeof(Node*) * 2);
  Node *new = (Node*)malloc(sizeof(Node));
  new->value = newval;
  new->next = tmp;
  new->prev = tmp->prev;
  tmp->prev->next = new;
  tmp->prev = new;
  return (&new->value);
}

//удаляет и освобождает заданный узел
void erase(double* what){
  Node *tmp = (Node*)((long long)what - 2 * sizeof(Node*));
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  printf("%0.3lf\n", tmp->value);
  free(tmp);
}

void printList(Node* head){
  Node *tmp = head;
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
    printList((Node*)((long long)list - 2 * sizeof(Node*)));
    printf("===\n");
    freeList(list);
    count = 1;
  }

  return 0;
}
