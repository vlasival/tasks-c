#include <stdio.h>


int main(){
  char c0, c1;
  while (1){
    if (scanf("%c", &c0) != 1){
      return 0;
    }

    else{
      if (c0 != '/'){
        printf("%c", c0);
        continue;
      }
      else{
        if (scanf("%c", &c1) != 1){
          printf("/");
          return 0;
        }
        else if (c1 == '/'){
          if (scanf("%c", &c0) != 1){
            return 0;
          }
          while (c0 != '\n'){
            if (scanf("%c", &c0) != 1){
              return 0;
            }
          }
          printf("%c", '\n');
        }
        else if (c1 == '*'){
          if (scanf("%c", &c0) != 1){
            return 0;
          }
          if (c0 == '\n'){
            printf("%c", '\n');
          }

          if (scanf("%c", &c1) != 1){
            return 0;
          }
          if (c1 == '\n'){
            printf("%c", '\n');
          }

          while (!((c0 == '*') && (c1 == '/'))) {
            c0 = c1;
            if (scanf("%c", &c1) != 1){
              return 0;
            }
            if (c1 == '\n'){
              printf("%c", '\n');
              c0 = c1;
            }
          }
        }
        else{
          printf("%c%c", c0, c1);
        }
      }
    }
  }
}
