#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(push, 1)

typedef unsigned long long ul;

typedef struct file_s{
  char name[21];
  ul size;
  char isDir;
  ul create;
  ul edit;
  char isHidden;
} file;
#pragma pack(pop)

int main(){
  FILE *input = fopen("input.txt", "rb");
  FILE *output = fopen("output.txt", "wb");
  int n, count = 0, tmp;
  ul a, b;
  fread(&n, sizeof(int), 1, input);
  file* array = (file*)malloc(sizeof(file) * n);
  int* res = (int*)malloc(sizeof(int) * n);
  fread(&a, sizeof(ul), 1, input);
  fread(&b, sizeof(ul), 1, input);
  for (int i = 0; i < n; i++){
    fread(&array[i], sizeof(file), 1, input);
  }
  for (int i = 0; i < n; i++){
    if (array[i].isHidden == 0 && array[i].isDir == 0){
      if (array[i].create >= a && array[i].edit <= b){
        *(res + count) = i;
        count++;
      }
    }
  }
  for (int i = 0; i < count - 1; i++){
    for (int j = i + 1; j < count; j++){
      if (strcmp(array[res[i]].name, array[res[j]].name) > 0){
        tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
      }
    }
  }
  for (int i = 0; i < count; i++){
    fwrite(&array[res[i]], sizeof(file), 1, output);
  }
  free(array);
  free(res);
  fclose(input);
  fclose(output);
  return 0;
}
