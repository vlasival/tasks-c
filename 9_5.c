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
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n;
  fread(&n, sizeof(int), 1, input);
  int *arr = (int *)malloc(sizeof(int) * n);
  fread(arr, sizeof(int), n, input);
  quicksort(arr, 0, n - 1);
  fwrite(arr, sizeof(int), n, output);
  free(arr);
  fclose(input);
  fclose(output);
  return 0;
}
