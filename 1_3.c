#include <stdio.h>

int main(){
  int a, sum = 0, i = 0, b;
  scanf("%d\n", &a);
  while(i < a){
    scanf("%d", &b);
    if (b % 2 == 0) sum += b;
    i++;
  }
  printf("%d\n", sum);
  return 0;
}
