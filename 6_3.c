#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char** elem, int len, int count, char *str){
  char *p = malloc(sizeof(char) * (len + 1));
  strcpy(p, str);
  elem[count] = p;
}


int main(){
  char* array[100001] = {0};
  char str[100001] = {0};
  int n, t, tmp, count = 0, res;
  char ch;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &t);
    switch (t) {
      case 0:
        scanf("%d", &tmp);
        scanf("%s", str);
        insert(array, tmp, count, str);
        count++;
        break;
      case 1:
        scanf("%d", &tmp);
        free(array[tmp]);
        array[tmp] = 0;
        break;
      case 2:
        scanf("%d", &tmp);
        printf("%s\n", array[tmp]);
        break;
      case 3:
        scanf("%d %c", &tmp, &ch);
        res = 0;
        for (int j = 0; array[tmp][j] != 0; j++){
          if (ch == array[tmp][j]){
            res++;
          }
        }
        printf("%d\n", res);
        break;
    }
  }
  for (int i = 0; i < count; i++){
    if (array[i] != 0){
      free(array[i]);
    }
  }
}
