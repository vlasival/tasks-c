#include <stdio.h>
#define LENGTH 100000
int main(){
  int arr[LENGTH] = {0}, n, tmp, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &tmp);
    arr[tmp]++;
  }
  for (i = 0; i < LENGTH; i++){
    if (arr[i] != 0){
      printf("%d: %d\n", i, arr[i]);
    }
  }
}
