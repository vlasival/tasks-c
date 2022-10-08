#include <stdio.h>
#define N 5000

int main(){
  int arr[N] = {0}, t, max = -10001, tmp, l, r;
  scanf("%d", &t);
  for (int i = 0; i < t; i++){
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < t; i++){
    tmp = 0;
    for (int j = i; j < t; j++){
      tmp += arr[j];
      if (tmp > max){
        max = tmp;
        l = i;
        r = j;
      }
    }
  }
  printf("%d %d %d", l, r, max);
}
