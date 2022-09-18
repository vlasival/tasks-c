#include <stdio.h>
#include <math.h>

int main(){
  int n, i, j, tmp, k = 0;
  scanf("%d", &n);
  printf("2\n");
  for (i = 3; i <= n; i += 2){
    tmp = sqrt(i) + 1;
    for (j = 2; j <= tmp; j++){
      if (i % j == 0){
        k = 1;
        break;
      }
    }
    if (k == 0){
      printf("%d\n", i);
    }
    k = 0;
  }
}
