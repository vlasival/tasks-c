#include <stdio.h>


int main(){
  int n, q, val, index, left, right, tmp = 0;
  int array[200010];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%d", &val);
    val += tmp;
    left = 0;
    right = n - 1;
    do{
      index = (right + left) / 2;
      if (array[index] > val){
        right = index;
      }
      else {
        left = index;
      }
    } while (right > left + 1);

    if (array[index + 1] == val){
      index++;
      while(array[index + 1] == val){
        index++;
      }
      tmp = index;
    }
    else if (array[index] == val){
      tmp = index;
    }
    else if (array[index - 1] == val){
      index--;
      tmp = index;
    }
    else{
      tmp = -1;
    }

    printf("%d\n", tmp);
  }
}
