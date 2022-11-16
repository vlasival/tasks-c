#include <stdio.h>
#define N 200010

typedef struct List {
  int data, prev, next;
} List;

void insertAfter(List *array, int index, int value, int count){
  array[count].data = value;
  array[count].next = array[index].next;
  array[count].prev = index;
  array[index].next = count;
  array[array[count].next].prev = count;
}

void insertBefore(List *array, int index, int value, int count){
  array[count].data = value;
  array[count].prev = array[index].prev;
  array[count].next = index;
  array[index].prev = count;
  array[array[count].prev].next = count;
}

void pop(List *array, int index){
  printf("%d\n", array[index].data);
  array[array[index].next].prev = array[index].prev;
  array[array[index].prev].next = array[index].next;
}

void printList(List *array){
  int i = 0;
  i = array[i].next;
  if (i == 0){
    printf("\n");
    return;
  }
  for(; array[i].next != 0; i = array[i].next){
    printf("%d\n", array[i].data);
  }
  printf("%d\n", array[i].data);
}
int main(){
  List array[N] = {0};
  int t, n, f, l, q, tmp, index, value;
  scanf("%d", &t);
  for (int i = 0; i < t; i++){
    scanf("%d%d%d%d", &n, &f, &l, &q);
    f++;
    l++;
    array[0].next = f;
    array[0].prev = l;
    for (int j = 1; j <= n; j++){
      scanf("%d%d%d", &array[j].data, &array[j].next, &array[j].prev);
      array[j].next += 1;
      array[j].prev += 1;
    }
    n++;
    for(int j = 0; j < q; j++){
      scanf("%d%d", &tmp, &index);
      switch (tmp) {
        case 1:
          scanf("%d", &value);
          insertAfter(array, index + 1, value, n);
          printf("%d\n", n - 1);
          n++;
          break;
        case -1:
          scanf("%d", &value);
          insertBefore(array, index + 1, value, n);
          printf("%d\n", n - 1);
          n++;
          break;
        case 0:
          pop(array, index + 1);
          break;
      }
    }
    printf("===\n");
    printList(array);
    printf("===\n");
  }
}
