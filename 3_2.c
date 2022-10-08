#include <stdio.h>

int main(){
  int n, arr[100001], res = 0, i, j;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++){
    for (j = i; j < n; j = j + i + 1){
      res += arr[j];
    }
    printf("%d\n", res);
    res = 0;
  }
  return 0;
}
