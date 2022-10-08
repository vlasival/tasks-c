#include <stdio.h>
#define N 5

int main(){
  int a[N], b[N], c[N] = {0};
  for (int i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N; i++){
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < N; i++){
    c[i] = a[i] && b[i];
    printf("%d ", c[i]);
  }
}
