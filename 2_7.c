#include <stdio.h>

int main(){
  int a, b, c, res = 0, j = 1;
  scanf("%d %d %d", &a, &b, &c);
  for (int i = a; i < b; i++){
    while (i + j * (c - 1) <= b){
      if (i + j * c > b){
        res++;
      }
      j++;
    }
    j = 1;
  }
  printf("%d\n", res);
}
