#include <stdio.h>

int main(){
  int n, a = 1, b = 1;
  long long res = 0;
  scanf("%d", &n);
  while ((n / (a*b)) > (b - 1)) {
    while ((n / (a * b)) > (b - 1)){
      res += n / (a * b) - (b - 1);
      b++;
    }
    a++;
    b = a;
  }
  printf("%lld\n", res);
  return 0;
}
