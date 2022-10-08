#include <stdio.h>

void summa(char *a, int b, int *len){
  int tmp = 0;
  int i = 0, t;
  for (i = 0; i < *len; i++){
    t = (tmp + a[i] * b);
    a[i] = t % 10;
    tmp = t / 10;
  }
  while(tmp > 0){
    a[i] = tmp % 10;
    tmp /= 10;
    i++;
  }
  *len = i;
}

int main(){
  char a[3001] = {0};
  int n, len = 1, i = 0;
  a[0] = 1;
  scanf("%d", &n);
  for (int i = 2; i < n + 1; i++){
    summa(a, i, &len);
  }

  for(int j = len - 1; j >= 0; j--){
    printf("%c", a[j] + '0');
  }
}
