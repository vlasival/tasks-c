#include <stdio.h>
#include <stdlib.h>
#define N 719


unsigned somehash1(char *key, int start, int len, int table){
  unsigned hash = 0x118;
  int dif = len / N + 1;
  for(int i = 0; i < len; i = i + dif) {
    hash += key[start + i];
    hash += (hash << 10);
    hash += (hash << 3);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 14);
  return hash % table;
}

unsigned somehash2(char *key, int start, int len, int table){
  unsigned hash = 0x45D9F3B;
  int dif = len / N + 1;
  for (int i = 0; i < len; i = i + dif){
    hash += key[start + i];
    // hash = hash * ((hash >> 16) + 1);
    hash ^= hash << 5;
  }
  return hash % table;
}


typedef struct {
  unsigned h1;
  int color;
} Node;

int addTable(Node *arr, int hash, int hash1, char *tmp, int cnt, int table){
  while (arr[hash].color != 0) {
    if (arr[hash].h1 == hash1){
      return arr[hash].color;
    }
    hash = (hash + 13) % table;
  }
  arr[hash].h1 = hash1;
  arr[hash].color = cnt;
  return -1;
}

// int mypow(int n, int m){
//   if (m == 0){
//     return 1;
//   }
//   for (int i = 0; i < m - 1; i++){
//     n *= n;
//   }
//   return n;
// }

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  char *str = malloc(sizeof(char) * (n + 1));
  scanf("%s", str);


  int k = (n - m + 1);
  Node *arr = calloc(sizeof(Node), (k + 111));

  unsigned hash1, hash2, cnt = 1;
  int res;


  for (int i = 0; i < k; i++){
    hash1 = somehash1(str, i, m, (k + 111));
    hash2 = somehash2(str, i, m, (k + 111));
    res = addTable(arr, hash1, hash2, str, cnt, (k + 111));
    if (res != -1){
      printf("%d ", res - 1);
    }
    else{
      printf("%d ", cnt - 1);
      cnt++;
    }
  }
}
