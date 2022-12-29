#include <stdio.h>
#include <stdlib.h>


void msort(int *a, int n)
{
  if (n < 2) return;
  msort(a, n / 2);
  msort(&a[n / 2], (n - 1) / 2 + 1);
  int* tmp = (int*)malloc(sizeof(int) * n);
  int id = 0, l = 0, r = n / 2;
  while ((l < n / 2) && (r < n))
    if (a[l] < a[r])
      tmp[id++] = a[l++];
    else
      tmp[id++] = a[r++];
  while (l < n / 2) {
    tmp[id++] = a[l++];
  }
  while (r < n) {
    tmp[id++] = a[r++];
  }
  for (l = 0; l < n; l++){
    a[l] = tmp[l];
  }
  free(tmp);
}

int main() {
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n;
  fread(&n, sizeof(int), 1, input);
  int *arr = (int *)calloc(sizeof(int), n);
  fread(arr, sizeof(int), n, input);
  msort(arr, n);
  fwrite(arr, sizeof(int), n, output);
  free(arr);
  fclose(input);
  fclose(output);
  return 0;
}
