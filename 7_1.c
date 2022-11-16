#include <stdio.h>

#define N 10010

int main(){
  int index[N];
  int sorted[N];
  char str[N][8];
  int n, tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &tmp);
    scanf("%s", str[i]);
    index[i] = tmp;
    // max = tmp > max ? tmp : max;
  }
  for (int i = 0; i < n; i++){
    sorted[i] = index[i];
  }
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      if (sorted[i] > sorted[j]){
        tmp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = tmp;
      }
    }
  }
  tmp = -1;
  for (int i = 0; i < n; i++){
    if (tmp == sorted[i]){
      continue;
    }
    for (int j = 0; j < n; j++){
      if (sorted[i] == index[j]){
        printf("%d %s\n", index[j], str[j]);
      }
    }
    tmp = sorted[i];
  }
}
