#include <stdio.h>

int main(){
  int n, q, val, index, left, right, delta, tmp;
  int array[200010];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%d", &val);
    left = 0;
    right = n - 1;
    while (right > (left + 1)){
      index = (right + left) / 2;
      if (array[index] > val){
        right = index;
      }
      else {
        left = index;
      }
    }

    if (val <= array[left]){
      printf("%d %d\n", left, array[left] - val);
    }
    else if (val >= array[right]){
      printf("%d %d\n", right, val - array[right]);
    }
    else{
      if (val - array[left] > array[right] - val){
        printf("%d %d\n", right, array[right] - val);
      }
      else {
        printf("%d %d\n", left, val - array[left]);
      }
    }
  }
  return 0;
}
