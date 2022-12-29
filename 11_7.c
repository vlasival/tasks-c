#include <stdio.h>
#include <stdlib.h>
#define N 200000

typedef struct {
  unsigned key, data;
} Node;

unsigned findOrAdd(Node *arr, unsigned num, unsigned i){
  unsigned tmp = num % N;
  while(arr[tmp].key != 0){
    if (arr[tmp].data == num){
      return arr[tmp].key;
    }
    tmp = (tmp + 1) % N;
  }
  arr[tmp].key = i;
  arr[tmp].data = num;
  return 0;
}

int main(){
  Node *arr = calloc(sizeof(Node), N);
  unsigned num, tmp;
  for (unsigned i = 1; ; i++){
    printf("eval %u\n", i);
    fflush(stdout);
    scanf("%u", &num);
    tmp = findOrAdd(arr, num, i);
    if (tmp != 0){
      printf("answer %d %d\n", tmp, i);
      fflush(stdout);
      return 0;
    }
  }
}
