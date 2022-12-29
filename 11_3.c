#include <stdio.h>
#include <stdlib.h>
#define SIZE 2200001

typedef unsigned long long ull;

typedef struct{
  ull val;
  int num;
} Node;

ull func(ull s, ull m, int a, int b, int c) {
  return (s*s*a + s*b + c) % m;
}

int hashFunc(ull n) {
  // n = (n >> 1) ^ n;
  n = (n >> 16) ^ n;
  return (int)(n % SIZE);
}

int findOrAdd(Node *arr, int i, ull s, int cnt){
  while(arr[i].num != 0){
    if (arr[i].val == s){
      return (arr[i].num);
    }
    i = (i + 1) % SIZE;
  }
  arr[i].num = cnt;
  arr[i].val = s;
  return -1;
}

int main(){
  ull m;
  int a, b, c, cnt = 1, res;
  ull s = 1;
  scanf("%llu%d%d%d", &m, &a, &b, &c);
  Node *arr = malloc(sizeof(Node) * SIZE);
  res = findOrAdd(arr, hashFunc(s), s, cnt);
  while(res == -1){
    s = func(s, m, a, b, c);
    cnt++;
    res = findOrAdd(arr, hashFunc(s), s, cnt);
  }
  printf("%d %d", res - 1, cnt - 1);
}
