#include <stdio.h>

int main(){
  char sym;
  int n = 0, k = 0;
  while (1){
    scanf("%c", &sym);
    if (sym == '\n'){
      break;
    }
    else if (sym == '.'){
      k = 0;
      continue;
    }
    else{
      if (k == 0){
        n++;
        k = 1;
      }
    }
  }
  printf("%d\n", n);
}
