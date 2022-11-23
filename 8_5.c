#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

void reverse(unsigned char *a) {
  unsigned char tmp = *a, res = 0;
  for (short i = 0; i < 7; i++) {
    res = res | (tmp & 1);
    res = res << 1;
    tmp = tmp >> 1;
  }
  res = res | (tmp & 1);
  *a = res;
}

int main() {
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  unsigned int n, l, cnt = 0;
  unsigned char tmp;
  fread(&n, sizeof(unsigned int), 1, input);
  ull *array = (ull *)calloc(sizeof(ull), n);
  unsigned char *nums = (unsigned char *)calloc(sizeof(unsigned char), n);
  for (int i = 0; i < n; i++) {
    fread(&l, sizeof(unsigned int), 1, input);
    nums[i] = l;
    for (int j = 0; j < l; j++) {
      fread(&tmp, sizeof(char), 1, input);
      array[i] = array[i] << 1;
      array[i] = array[i] | tmp;
    }
  }
  cnt = 0;
  tmp = 0;
  fread(&n, sizeof(int), 1, input);
  for (int i = 0; i < n; i++) {
    fread(&l, 2, 1, input);
    for (char j = nums[l] - 1; j >= 0; j--) {
      tmp = tmp << 1;
      tmp = tmp | ((array[l] >> j) & 1);
      cnt += 1;
      if (cnt == 8) {
        cnt = 0;
        reverse(&tmp);
        fwrite(&tmp, sizeof(unsigned char), 1, output);
        tmp = 0;
      }
    }
  }
  if (cnt > 0) {
    for (short i = cnt; i < 8; i++) {
      tmp = tmp << 1;
    }
    reverse(&tmp);
    fwrite(&tmp, sizeof(char), 1, output);
  }
  free(array);
  free(nums);
  fclose(input);
  fclose(output);
}
