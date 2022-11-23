#include <stdio.h>

typedef union byt{
  int num;
  char byte[4];
} bytes;

void reverse(bytes* a){
  char tmp;
  tmp = a->byte[0];
  a->byte[0] = a->byte[3];
  a->byte[3] = tmp;
  tmp = a->byte[1];
  a->byte[1] = a->byte[2];
  a->byte[2] = tmp;
  return;
}

int main() {
  FILE *input;
  input = fopen("input.txt", "rb");
  FILE *output;
  output = fopen("output.txt", "wb");
  bytes tmp, res, n;
  res.num = 0;
  short flag = 0;
  fread(&n.num, sizeof(int), 1, input);
  if (n.num > 10000){
    flag = 1;
    reverse(&n);
  }
  for (int i = 0; i < n.num; i++){
    fread(&tmp.num, sizeof(int), 1, input);
    if (flag == 1){
      reverse(&tmp);
    }
    res.num += tmp.num;
  }
  if (flag == 1){
    reverse(&res);
  }
  fwrite(&res.num, sizeof(int), 1, output);
  fclose(input);
  fclose(output);
  return 0;
}
