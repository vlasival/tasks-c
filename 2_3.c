#include <stdio.h>

int main(){
  int a, b, plus = 0, minus = 0, nol = 0;
  double f;
  scanf("%d\n", &a);
  for(int i = 0; i < a; i++){
    scanf("%d", &b);
    if (b > 0){
      plus++;
    }
    else if (b < 0){
      minus++;
    }
    else{
      nol++;
    }
  }
  f = plus + minus + nol;
  printf("%0.6lf %0.6lf %0.6lf\n", minus / f, nol / f, plus / f);
}
