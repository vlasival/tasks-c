#include <stdio.h>

int main(){
  int n, tmp1, tmp2, tmp3, min = 0, m;
  char arr[26];
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++){
    scanf("%c", &arr[i]);
    getchar();
  }
  min = arr[n - 1];
  for (int i = n - 2; i >= 0; i--){
    if (arr[i] < min){
      tmp1 = i;
      min = arr[tmp1];
      break;
    }
    min = arr[i];
  }
  m = 'z' + 1;
  for (int i = tmp1 + 1; i < n; i++){
    if (arr[i] > min){
      if (arr[i] < m){
        m = arr[i];
        tmp2 = i;
      }
    }
  }
  tmp3 = arr[tmp1];
  arr[tmp1] = arr[tmp2];
  arr[tmp2] = tmp3;
  m = (n - tmp1 - 1) / 2;
  while (m > 0){
    tmp3 = arr[tmp1 + m];
    arr[tmp1 + m] = arr[n - m];
    arr[n - m] = tmp3;
    m--;
  }
  for (int i = 0; i < n; i++){
    printf("%c ", arr[i]);
  }
}
