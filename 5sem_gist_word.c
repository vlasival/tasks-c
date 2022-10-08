#include <stdio.h>
#include <string.h>
struct word {
  char val[21]; //строка
  int num; // колво вхождений
};

struct word Gist[100];


int main(){
  int i = 0;
  char str[21];
  scanf("%s", str);
  while (!(strcmp(str, "finish"))){
    int n;
    for (n = 0; n < i; n++){
      if (!(strcmp(str, Gist[n].val))){
        Gist[n].num++;
        break;
      }
    }
    printf("%d   ", n);
    if (n == i){
      strcpy(Gist[i].val, str);
      Gist[i].num = 1;
      i++;
    }
    scanf("%s", str);
  }

  for (i = 0; i < 21; i++){
    printf("%d / %s", Gist[i].num, Gist[i].val);
  }
  return 0;
}
