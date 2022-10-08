#include <stdio.h>

typedef struct LongNum_s {
  int len; //сколько цифр в числе
  int arr[500]; //массив десятичных цифр числа
} LongNum;

void summa(LongNum *a, LongNum *b){
  short i = 0;
  short tmp = 0;
  b->len = a->len;
  for (i = 0; i < a->len; i++){
    tmp += a->arr[i] + b->arr[i];
    if (tmp > 9){
      b->arr[i] = tmp % 10;
      tmp = 1;
    }
    else{
      b->arr[i] = tmp;
      tmp = 0;
    }
  }
  if (tmp == 1){
    (b->len)++;
    b->arr[i] = 1;
  }
}

int main(){
  LongNum a = {1, {0}}, b = {1, {0}};
  int n, i = 0;
  a.arr[0] = 1;
  b.arr[0] = 1;
  scanf("%d", &n);
  while (i < n - 2){
    if (i % 2 == 0){
      summa(&a, &b);
    }
    else{
      summa(&b, &a);
    }
    i++;
  }
  if (i % 2 == 0){
    for (int j = a.len - 1; j >= 0; j--){
      printf("%d", a.arr[j]);
    }
  }
  else{
    for (int j = b.len - 1; j >= 0; j--){
      printf("%d", b.arr[j]);
    }
  }
}
