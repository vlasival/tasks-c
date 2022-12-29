#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
  union {
    unsigned inn;
    unsigned char byte[4];
  };
  unsigned value;
} Node;

void radix(Node *arr, int n) {
  for (int j = 0; j < 4; j++) {
    unsigned *cnt = calloc(sizeof(int), 256);
    Node *new = malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
      if (arr[i].byte[j] < 255) {
        cnt[arr[i].byte[j] + 1]++;
      }
    }

    for (int i = 1; i < 256; i++) {
      cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i < n; i++) {
      new[cnt[arr[i].byte[j]]].inn = arr[i].inn;
      new[cnt[arr[i].byte[j]]].value = arr[i].value;
      cnt[arr[i].byte[j]]++;
    }

    for (int i = 0; i < n; i++){
      arr[i] = new[i];
    }

    free(cnt);
    free(new);
  }
}

int main() {
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n;
  fread(&n, sizeof(int), 1, input);
  Node *arr = (Node *)malloc(sizeof(Node) * n);
  fread(arr, sizeof(Node), n, input);
  radix(arr, n);
  fwrite(arr, sizeof(Node), n, output);
  free(arr);
  fclose(input);
  fclose(output);
  return 0;
}
