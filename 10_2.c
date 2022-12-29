#include <stdio.h>
#include <stdlib.h>
#define M 1000010

typedef struct Node_s{
  int size;
  char *str;
} Node;

int main(){
  int n, idx;
  char tmp[8];
  scanf("%d", &n);
  Node *arr = calloc(sizeof(Node), M);
  for (int i = 0; i < n; i++){
    scanf("%d", &idx);
    arr[idx].size += 1;
    arr[idx].str = realloc(arr[idx].str, sizeof(char) * arr[idx].size * 8);
    scanf("%s", arr[idx].str + (arr[idx].size - 1) * 8);
  }
  for (int i = 0; i < M; i++){
    if (arr[i].size != 0){
      for(int j = 0; j < arr[i].size; j++){
        printf("%d %s\n", i, arr[i].str + 8 * j);
      }
    }
  }
  return 0;
}
