#include <stdio.h>
#define N 30002

int main(){
  unsigned long long array[N];
  int n, res = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%llx", &array[i]);
  }
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      if ((array[i] & array[j]) == 0){
        res++;
      }
    }
  }
  printf("%d\n", res);
}
