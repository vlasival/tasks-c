#include <stdio.h>
#define N 10000

int main(){
  int a[N] = {0}, t, tmp;
  scanf("%d", &t);
  for (int i = 0; i < t; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < t - 1; i++){
    for (int j = i + 1; j < t; j++){
      if (a[i] > a[j]){
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
  for (int i = 0; i < t; i++){
    printf("%d ", a[i]);
  }
}
