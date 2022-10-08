#include <stdio.h>
#define N 10
int main(){
  int arr[N] = {1, 5, 3, 4, 5, 6, 7, 9, 1, 2}, tmp;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      if (arr[j] < arr[i]){
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
      }
    }
  }
  for (int i = 0; i < N; i++){
    printf("%d ", arr[i]);
  }
}
