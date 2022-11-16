#include <stdio.h>
// #include <stdlib.h>

typedef unsigned char bitword;


//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero(bitword *arr, int num){
  int tmp = num / 8 + 1;
  for (int i = 0; i < tmp; i++){
    arr[i] = 0;
  }
}


//возвращает значение idx-ого бита (0 или 1)
int bitsetGet(const bitword *arr, int idx){
  int ost;
  ost = idx % 8;
  return ((arr[idx / 8] & (1 << ost)) != 0);
}


//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet(bitword *arr, int idx, int newval){
  int byte, tmp;
  byte = idx / 8;
  tmp = idx % 8;
  if (newval == 0){
    arr[byte] = arr[byte] & ~(1 << tmp);
  }
  else{
    arr[byte] = arr[byte] | (1 << tmp);
  }
}


//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny(const bitword *arr, int left, int right){
  int start, stop;
  start = (left - 1) / 8 + 1;
  stop = right / 8;
  for (int i = start; i < stop; i++){
    if (arr[i] != 0){
      return 1;
    }
  }
  start = left / 8 + 1;
  bitword onebyte;
  if ((left / 8) != (right / 8)){
    onebyte = ~((1 << (left % 8)) - 1);
    if ((arr[start - 1] & onebyte) != 0){
      return 1;
    }

    onebyte = (1 << (right % 8)) - 1;
    if ((arr[stop] & onebyte) != 0){
      return 1;
    }
    return 0;
  }
  else{
    onebyte = ((1 << (right % 8)) - 1) - ((1 << (left % 8)) - 1);
    if ((arr[stop] & onebyte) != 0){
      return 1;
    }
    return 0;
  }
}


int main(){
  int n, tmp, val;
  short t;
  bitword array[2500010];
  scanf("%d", &n);
  // scanf("%hd", &t);
  // scanf("%d", &tmp);
  // bitsetZero(array, tmp);
  for (int i = 0; i < n; i++){
    scanf("%hd", &t);
    switch (t) {
      case 0:
        scanf("%d", &tmp);
        // free(array);
        bitsetZero(array, tmp);
        break;
      case 1:
        scanf("%d", &tmp);
        printf("%d\n", bitsetGet(array, tmp));
        break;
      case 2:
        scanf("%d%d", &tmp, &val);
        bitsetSet(array, tmp, val);
        break;
      case 3:
        scanf("%d%d", &tmp, &val);
        if (bitsetAny(array, tmp, val) == 1){
          printf("some\n");
        }
        else {
          printf("none\n");
        }
        break;
    }
  }
}
