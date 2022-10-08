#include <stdio.h>
#define SIZE 90001

int main(){
  int arr1[SIZE] = {0}, arr2[SIZE] = {0}, tmp[301], n, p, i, a = 0, b = 0;
  scanf("%d %d", &n, &p);
  for (i = 1; i <= p; i++){
    scanf("%d %d", &arr1[i], &arr2[i]);
    tmp[arr1[i]]++;
  }
  for (i = 1; i <= p; i++){
    if (tmp[i] > 1){
      printf("0");
      return 0;
    }
  }
  printf("1 ");
  if (n == p){
    printf("2 ");
  }
  for (i = 1; i <= n; i++){
    tmp[i] = 0;
  }
  for (i = 1; i <= p; i++){
    tmp[arr2[i]]++;
  }
  for (i = 1; i <= n; i++){
    if (a == 0 && tmp[i] > 1){
      a = 1;
    }
    if (b == 0 && tmp[i] == 0){
      b = 1;
    }
  }

  if (a != 1){
    printf("3 ");
  }
  if (b != 1){
    printf("4 ");
  }
  if (a != 1 && b != 1){
    printf("5");
  }
}
