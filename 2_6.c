#include <stdio.h>

int int_pow(int a, int b){
  int res = a;
  if (b != 0){
    while (b > 1){
      res *= a;
      b -= 1;
    }
  }
  else{
    return(1);
  }
  return (res);
}

int main(){
  int k, res = 0;
  char tmp;
  scanf("%d\n", &k);
  for (int i = 0; i < k; i++){
    scanf("%c", &tmp);
    if (i != 0 && i % 8 == 0){
      printf("%d ", res);
      res = 0;
    }
    if (tmp == '1'){
      res += int_pow(2, i % 8);
    }
  }
  
  printf("%d ", res);

}
