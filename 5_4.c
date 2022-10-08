#include <stdio.h>


int main(){
  int n, prime[15000000] = {0}, q;
  scanf("%d", &n);
  scanf("%d", &q);
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i * i < n; i++){
    if (prime[i] == 0){
      for (int j = i * i; j < n; j+=i){
        prime[j] = 1;
      }
    }
  }
  for (int i = 0; i < q; i++){
    scanf("%d", &n);
    if (prime[n] == 0){
      printf("%d prime\n", n);
    }
    else{
      printf("%d not\n", n);
    }
  }
}
