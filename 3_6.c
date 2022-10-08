#include <stdio.h>
#define N 100001


int main(){
  int a[N] = {0}, b[N] = {0}, c[N] = {0}, na, nb, tmp, i, max2 = 0;

  scanf("%d", &na);
  for (i = 0; i < na; i++){
    scanf("%d", &tmp);
    a[tmp] = 1;
  }
  scanf("%d", &nb);
  for (i = 0; i < nb; i++){
    scanf("%d", &tmp);
    b[tmp] = 1;
  }
  for (i = 0; i < N; i++){
    c[i] = a[i] && !(b[i]);
  }

  for (i = 0; i <= N; i++){
    if (c[i] == 1){
      max2++;
    }
  }
  printf("%d\n", max2);
  if (max2 != 0){
    for (i = 0; i <= N; i++){
      if (c[i] == 1){
        printf("%d ", i);
      }
    }
  }
}
