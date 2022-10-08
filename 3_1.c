#include <stdio.h>

int main(){
  int n, arr[101], res, i, j;
  scanf("%d\n", &n);
  for (int p = 0; p < n; p++){
    scanf("%d", &arr[p]);
  }
  for (i = 0; i < n; i++){
    for (j = i; j < n; j++){
      if (arr[j] < arr[i]){
        res++;
      }
    }
    printf("%d ", res);
    res = 0;
  }
  return 0;
}
