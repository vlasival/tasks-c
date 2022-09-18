#include <stdio.h>

int main(){
  int a, b, c;
  scanf("%d %d", &a, &b);
  if (a % b == 0){
    c = a / b;
    printf("%d %d %d %d", c, c, c, 0);
    return 0;
  }
  else{
    if (a > 0){
      c = a / b;
      printf("%d %d %d %d", c, c+1, c, a%b);
    }
    else if (a == 0){
      printf("0 0 0 %d", b);
    }
    else if (a < 0){
      c = a / b;
      printf("%d %d %d %d", c-1, c, c, a%b + b);
    }
  return 0;
}
}
