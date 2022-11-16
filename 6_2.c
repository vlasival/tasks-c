#include <stdio.h>

typedef struct List{
  char data[8];
  int next;
}List;

void insert(List *arr, int index, char data[8], int *n, int *fst){
  if (index == -1){
    for (int i = 0; i < 8; i++){
      arr[*n].data[i] = data[i];
    }
    arr[*n].next = *fst;
    *fst = *n;
    printf("%d\n", *n);
    *n += 1;
    return;
  }
  for (int i = 0; i < 8; i++){
    arr[*n].data[i] = data[i];
  }
  arr[*n].next = arr[index].next;
  arr[index].next = *n;
  printf("%d\n", *n);
  *n += 1;
}

void pop(List *arr, int index, int *n, int *fst) {
  int tmp;
  if (index == -1){
    printf("%s\n", arr[*fst].data);
    *fst = arr[*fst].next;
  }
  else{
    tmp = arr[index].next;
    arr[index].next = arr[tmp].next;
    printf("%s\n", arr[tmp].data);
  }
}

void printList(List *arr, int fst){
  if (fst == -1){
    printf("\n");
  }
  else{
    while (arr[fst].next != -1) {
      printf("%s\n", arr[fst].data);
      fst = arr[fst].next;
    }
    printf("%s\n", arr[fst].data);
  }
}

int main(){
  List array[200002] = {0};
  int t, n, first, quest, next, temp, index;
  char tmp[8];
  scanf("%d", &t);
  for (int i = 0; i < t; i++){
    scanf("%d%d%d", &n, &first, &quest);
    for (int j = 0; j < n; j++){
      scanf("%s", tmp);
      scanf("%d", &next);
      for (int g = 0; g < 8; g++){
        array[j].data[g] = tmp[g];
      }
      array[j].next = next;
    }

    for (int j = 0; j < quest; j++){
      scanf("%d%d", &temp, &index);
      if (temp == 0){
        scanf("%s", tmp);
        insert(array, index, tmp, &n, &first);
      }
      else {
        pop(array, index, &n, &first);
      }

    }
    printf("===\n");
    printList(array, first);
    printf("===\n");
  }
}
