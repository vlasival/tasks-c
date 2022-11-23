#include <stdio.h>
#include <stdlib.h>

int merge(const int *a, int ak, const int *b, int bk, int *res) {
  int k = 0, l = 0;
  while (k < ak && l < bk) {
    if (a[k] < b[l]) {
      res[k + l] = a[k];
      k++;
    } else {
      res[k + l] = b[l];
      l++;
    }
  }
  while (k < ak) {
    res[k + l] = a[k];
    k++;
  }
  while (l < bk) {
    res[k + l] = b[l];
    l++;
  }
  return (ak + bk);
}

int main() {
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n, m;
  fread(&n, sizeof(int), 1, input);
  fread(&m, sizeof(int), 1, input);
  int *arr1 = (int *)calloc(sizeof(int), n);
  int *arr2 = (int *)calloc(sizeof(int), m);
  int *res = (int *)calloc(sizeof(int), (m + n));

  for (int i = 0; i < n; i++) {
    fread(&arr1[i], sizeof(int), 1, input);
  }
  for (int i = 0; i < m; i++) {
    fread(&arr2[i], sizeof(int), 1, input);
  }
  int cnt = merge(arr1, n, arr2, m, res);
  for (int i = 0; i < cnt; i++) {
    fwrite(&res[i], sizeof(int), 1, output);
  }
  free(arr1);
  free(arr2);
  free(res);
  fclose(input);
  fclose(output);
  return 0;
}
