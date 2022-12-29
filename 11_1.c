#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
  int num;
  struct Node_s *next;
} Node;

int hashFunc(int n, int size) {
  n = (n >> 16) ^ n;
  return (n % size);
}

Node *init() {
  Node *new = malloc(sizeof(Node));
  new->next = 0;
  return new;
}

void addEnd(Node **arr, int i, int elem, int *nums, int *cnt) {
  Node *tmp = arr[i];
  while (tmp->next != 0) {
    if (tmp->next->num == elem) {
      return;
    }
    tmp = tmp->next;
  }
  Node *new = malloc(sizeof(Node));
  new->next = 0;
  new->num = elem;
  tmp->next = new;
  nums[*cnt] = i;
  *cnt += 1;
}

int delplus(Node **arr, int i) {
  int res = arr[i]->next->num;
  Node *tmp = arr[i]->next;
  arr[i]->next = arr[i]->next->next;
  free(tmp);
  return res;
}

void freeList(Node** arr, int n) {
  Node *tmp, *pmt;
  for (int i = 1; i < n; i++){
    tmp = arr[i];
    while(tmp->next != 0){
      pmt = tmp;
      tmp = tmp->next;
      free(pmt);
    }
    free(tmp);
  }
}

int main() {
  FILE *input = fopen("input.bin", "rb");
  FILE *output = fopen("output.bin", "wb");
  int n, tmp, cnt = 0;
  fread(&n, sizeof(int), 1, input);
  if (n == 0){
    fwrite(&n, sizeof(int), 1, output);
    return 0;
  }
  Node **arr = malloc(sizeof(Node *) * (n + 1));
  int *nums = malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n + 1; i++) {
    arr[i] = init();
  }
  for (int i = 0; i < n; i++) {
    fread(&tmp, sizeof(int), 1, input);
    addEnd(arr, hashFunc(tmp, n), tmp, nums, &cnt);
  }

  fwrite(&cnt, sizeof(int), 1, output);

  for (int i = 0; i < cnt; i++) {
    tmp = delplus(arr, nums[i]);
    fwrite(&tmp, sizeof(int), 1, output);
  }

  freeList(arr, n + 1);
  free(nums);
  return 0;
}
