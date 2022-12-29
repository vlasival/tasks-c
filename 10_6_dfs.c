#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s{
  int num;
  struct Node_s *next;
} Node;


void addEnd(Node* head, int id){
  while (head->next != 0){
    if (head->next->num >= id){
      break;
    }
    head = head->next;
  }
  Node* new = malloc(sizeof(Node));
  new->next = head->next;
  head->next = new;
  new->num = id;
}

int dfs(Node** arr, char* visited, int i, int* res, int* cnt, int* flag){
  if (*flag == 1){
    return 1;
  }
  if (visited[i] == -1){
    *flag = 1;
    return 1;
  }
  visited[i] = -1;
  Node* tmp = arr[i];
  while (tmp->next != 0){
    if (visited[tmp->next->num] != 1){
      dfs(arr, visited, tmp->next->num, res, cnt, flag);
    }
    if (*flag == 1){
      return 1;
    }
    tmp = tmp->next;
  }
  res[*cnt] = i;
  *cnt -= 1;
  visited[i] = 1;
  return 0;
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

void printList(Node* a){
  while(a->next != 0){
    printf("%d ", a->next->num);
    a = a->next;
  }
}

int main(){
  int n, q;
  int t1, t2;
  scanf("%d%d", &n, &q);
  int cnt = n - 1, flag = 0;
  Node **arr = malloc(sizeof(Node*) * (n + 1));
  char *visited = calloc(sizeof(char), (n + 1));
  int *res = malloc(sizeof(int) * n);
  for (int i = 1; i <= n; i++){
    Node* new = malloc(sizeof(Node));
    new->next = 0;
    arr[i] = new;
  }
  for (int i = 0; i < q; i++){
    scanf("%d%d", &t1, &t2);
    addEnd(arr[t1], t2);
  }

  for (int i = 1; i < n + 1; i++){
    if (visited[i] == -1){
      printf("bad course\n");
      return 0;
    }
    if (visited[i] == 0){
      dfs(arr, visited, i, res, &cnt, &flag);
      if (flag == 1){
        printf("bad course\n");
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++){
    printf("%d ", res[i]);
  }

  printf("\n");

  freeList(arr, (n + 1));
  free(arr);
  free(visited);
  free(res);
  return 0;
}
