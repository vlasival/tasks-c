#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned somehash(char *tmp, int start, int size, int table){
  unsigned key = 0;
	for (int i = 0; i < size; i++){
    key += (unsigned)tmp[start + i] << (i % 4);
  }
	key = key ^ (key >> 16);
	return key % table;
}

typedef struct {
  char *str;
  int color;
} Node;

int addTable(Node *arr, int hash, char *tmp, int start, int cnt, int table){

  while (arr[hash].color != -1) {
    if (strcmp(arr[hash].str, tmp + start) == 0){
      return arr[hash].color;
    }
    hash = (hash + 1) % table;
  }
  strcpy(arr[hash].str, tmp + start);
  arr[hash].color = cnt;
  return -1;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  char *str = malloc(sizeof(char) * (n + 1));
  scanf("%s", str);


  int k = (n - m + 1);
  Node *arr = malloc(sizeof(Node) * (k + 1));
  for (int i = 0; i < n; i++){
    arr[i].str = calloc(sizeof(char), (m + 1));
    arr[i].color = -1;
  }

  int hash, cnt = 0, res;
  char save;

  for (int i = 0; i < k; i++){
    hash = somehash(str, i, m, (k + 1));
    save = str[i + m];
    str[i + m] = 0;
    res = addTable(arr, hash, str, i, cnt, (k + 1));
    str[i + m] = save;
    if (res != -1){
      printf("%d ", res);
    }
    else{
      printf("%d ", cnt);
      cnt++;
    }
  }
}
