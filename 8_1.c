#include <stdio.h>
typedef long long ll;

int main() {

  FILE *input;
  input = fopen("input.txt", "rb");
  FILE *output;
  output = fopen("output.txt", "wb");
  int a, b;
  short tmp;
  long long c;
  fread(&a, sizeof(int), 1, input);
  fread(&b, sizeof(int), 1, input);
  c = ((ll)a + (ll)b);
  c = c < 0 ? (c + 1) / 2 - 1 : c / 2;
  fwrite(&c, sizeof(int), 1, output);
  fclose(input);
  fclose(output);
}
