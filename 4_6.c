#include <stdio.h>
#include <string.h>

int readTime(char *str, int *hour, int *mins, int *sec){
  int len = strlen(str), dotcount = 0, tmp = 0, i = 0;
  while(i < len){
    if (str[i] == '|'){
      return 1;
    }
    else if (str[i] == ':'){
      tmp++;
    }
    else if (tmp == 0){
      *hour *= 10;
      *hour += str[i] - '0';
    }
    else if (tmp == 1){
      *mins *= 10;
      *mins += str[i] - '0';
    }
    else if (tmp == 2){
      *sec *= 10;
      *sec += str[i] - '0';
    }
    i++;
  }
  return 0;
}

int main(){
  char str[16];
  int h = 0, m = 0, s = 0;
  scanf("%s", str);
  if (readTime(str, &h, &m, &s)){
      printf("0 -1 -1 -1\n0 -1 -1\n0 -1");
      return 0;
  }
  else if (h > 23 || m > 59 || s > 59){
    printf("0 -1 -1 -1\n0 -1 -1\n0 -1");
    return 0;
  }
  else{
    printf("1 %d %d %d\n", h, m, s);
    printf("1 %d %d\n", h, m);
    printf("1 %d", h);
  }
}
