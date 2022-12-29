#include <stdio.h>
#include <stdlib.h>


typedef struct Node_s{
  int num;
  struct Node_s *next;
} Node;


void addEnd(Node* head, int id){
  while (head->next != 0){
    head = head->next;
  }
  Node* new = malloc(sizeof(Node));
  new->next = head->next;
  head->next = new;
  new->num = id;
}

void freeList(Node** arr, int n) {
  Node *tmp, *pmt;
  for (int i = 1; i < n; i++){
    tmp = arr[i];
    while(tmp->next != 0){
      pmt = tmp;
      tmp = tmp->next;
      free(pmt);
    }
    free(tmp);
  }
}

void subCount(Node **arr, int j, int *count){
  Node *tmp = arr[j];
  while(tmp->next != 0){
    count[tmp->next->num]--;
    tmp = tmp->next;
  }
  count[j] = -1;
}

Node* init(Node **arr){
  Node* new = malloc(sizeof(Node));
  new->next = 0;
  return new;
}

int main(){
  int n, q;
  int t1, t2, cnt = 0;
  scanf("%d%d", &n, &q);
  Node **arr = malloc(sizeof(Node*) * (n + 1));
  int *count = calloc(sizeof(int), (n + 1));
  int *res = malloc(sizeof(int) * n);
  for (int i = 1; i <= n; i++){
    arr[i] = init(arr);
  }

  for (int i = 0; i < q; i++){
    scanf("%d%d", &t1, &t2);
    addEnd(arr[t1], t2);
    count[t2]++;
  }
  int j;
  for (int i = 0; i < n; i++){
    for (j = 1; j < n + 1; j++){
      if (count[j] == 0){
        res[cnt++] = j;
        subCount(arr, j, count);
        break;
      }
    }
    if (j == (n + 1)){
      printf("bad course\n");
      freeList(arr, n + 1);
      free(count);
      free(res);
      return 0;
    }
  }

  for (int i = 0; i < n; i++){
    printf("%d ", res[i]);
  }

  freeList(arr, n + 1);
  free(count);
  free(res);
  return 0;
}
