#include <stdio.h>
#include <stdlib.h>

void quicksort(int* arr, int left, int right){
  int l = left, r = right, pivot = arr[(left + right + 1) / 2], tmp;
  while(l <= r){
    while (arr[l] < pivot) l++;
    while (arr[r] > pivot) r--;
    if (l <= r){
      if (arr[l] > arr[r]){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
      }
      l++;
      r--;
    }
  }
  if (left < r) quicksort(arr, left, r);
  if (l < right) quicksort(arr, l, right);
}

int main() {
  int n, tmp, cnt = 1;
  scanf("%d", &n);
  int *arr = (int*)malloc(sizeof(int) * n);
  int *res = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  quicksort(arr, 0, n - 1);
  tmp = arr[0];
  res[0] = tmp;
  for (int i = 1; i < n; i++){
    if (arr[i] != tmp){
      tmp = arr[i];
      res[cnt++] = tmp;
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++){
    printf("%d\n", res[i]);
  }
  free(arr);
  free(res);
  return 0;
}
