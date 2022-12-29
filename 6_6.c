#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001

typedef struct sTokens{
  int num;
  char **arr;
} Tokens;

void tokensSplit(Tokens *tokens, const char *str, const char *delims){
  if(tokens->arr == NULL){
    tokens->num = 0;
    char tmp = 1;
    int i = 0;
    while (str[i] != 0){
      if (tmp && !(strchr(delims, str[i]))) {
        tokens->num++;
        tmp = 0;
      }
      if (!tmp && (strchr(delims, str[i]))) {
        tmp = 1;
      }
      i++;
    }
  }
  else{
    char slovo[N];
    int i = 0, len, count = 0;
    while (str[i] != 0){
      len = 0;
      while (!(strchr(delims, str[i])) && str[i] != 0) {
        slovo[len] = str[i];
        len++;
        i++;
      }
      slovo[len] = 0;
      if (len != 0){
        tokens->arr[count] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(tokens->arr[count], slovo);
        count++;
      }
      i++;
    }
  }
}

void tokensFree(Tokens *tokens){
  for(int i = 0; i < tokens->num; i++){
    free(tokens->arr[i]);
  }
  if(tokens->arr != NULL){
    free(tokens->arr);
  }
}

int main(){
  Tokens res = {0, NULL};
  char delims[] = ".,;:\0";
  char str[N];
  scanf("%s", str);
  tokensSplit(&res, str, delims);
  res.arr = (char**)malloc(sizeof(char*) * res.num);
  tokensSplit(&res, str, delims);
  printf("%d\n", res.num);
  for(int i = 0; i < res.num; i++){
    printf("%s\n", res.arr[i]);
  }
  tokensFree(&res);
  return 0;
}
