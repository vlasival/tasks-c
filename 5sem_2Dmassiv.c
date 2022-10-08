#include <stdio.h>
#define N 100




int main(){
  int arr[N][N] = {0};
  int tmp = 0, ch = 1, i;
  while (N - 1 - tmp > tmp){
    for (i = 0; i < N - 1 - tmp; i++){
      arr[tmp][i] = ch;
      ch++;
    }
    for (i = 0; i < N - 1 - tmp; i++){
      arr[i][N - 1 - tmp] = ch;
      ch++;
    }
    for (i = N - 1 - tmp; i >= tmp; i--){
      arr[N - tmp][i] = ch;
      ch++;
    }
    for (i = N - 1 - tmp; i >= tmp; i--){
      arr[i][tmp] = ch;
      ch++;
    }
  }
  for (i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      
    }
  }
  return 0;
}
