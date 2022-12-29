#include <stdio.h>
#include <stdlib.h>


void siftDown(int *arr, int i, int n) {
  int left = (2 * i + 1);
  int right = (2 * i + 2);
  int max = i;
  int tmp;

  if (left < n && arr[left] > arr[i]) {
    max = left;
  }

  if (right < n && arr[right] > arr[max]) {
    max = right;
  }
  if (max != i) {
    tmp = arr[i];
    arr[i] = arr[max];
    arr[max] = tmp;
    siftDown(arr, max, n);
  }
}

void buildHeap(int *arr, int n) {
  int mid = n / 2;
  for (int i = mid; i >= 0; i--){
    siftDown(arr, i, n);
  }
}

void heap(int *arr, int n) {
  buildHeap(arr, n);
  int size = n, tmp;
  for (int i = 0; i < n; i++) {
    tmp = arr[0];
    arr[0] = arr[n - i - 1];
    arr[n - i - 1] = tmp;
    size--;
    siftDown(arr, 0, size);
  }
}

int main() {
  FILE *input = fopen("input.bin", "rb");
  FILE *output = fopen("output.bin", "wb");
  int n;
  fread(&n, sizeof(int), 1, input);
  int *arr = malloc(sizeof(int) * n);
  fread(arr, sizeof(int), n, input);
  heap(arr, n);
  // buildHeap(arr, n);
  fwrite(arr, sizeof(int), n, output);
  fclose(input);
  fclose(output);
  return 0;
}
