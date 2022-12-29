#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int n, int pivot) {
  int *less = (int *)calloc(sizeof(int), n);
  int *ful = (int *)calloc(sizeof(int), n);
  int l = 0, f = 0;
  char flag = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > pivot) {
      ful[f++] = a[i];
    } else if (a[i] < pivot) {
      less[l++] = a[i];
    } else {
      if (flag == 0) {
        flag = 1;
        ful[f++] = a[i];
      } else {
        flag = 0;
        less[l++] = a[i];
      }
    }
  }
  for (int i = 0; i < l; i++) {
    a[i] = less[i];
  }
  for (int i = 0; i < f; i++) {
    a[i + l] = ful[i];
  }
  free(less);
  free(ful);
  return l;
}

int main() {
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n, p;
  fread(&n, sizeof(int), 1, input);
  fread(&p, sizeof(int), 1, input);
  int *arr = (int *)calloc(sizeof(int), n);
  fread(arr, sizeof(int), n, input);
  int res = partition(arr, n, p);
  fwrite(&res, sizeof(int), 1, output);
  fwrite(arr, sizeof(int), n, output);
  free(arr);
  fclose(input);
  fclose(output);
  return 0;
}
