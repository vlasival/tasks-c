#include <stdio.h>

int main(){
  int a, b, i = 0, min = 10001, max = -10001, posmin, posmax;
  scanf("%d\n", &a);
  while(i < a){
    scanf("%d", &b);
    if (b < min){
      min = b;
      posmin = i + 1;
    }
    if (b > max){
      max = b;
      posmax = i + 1;
    }
    i++;
  }
  printf("%d %d %d %d\n", min, posmin, max, posmax);
  return 0;
}
