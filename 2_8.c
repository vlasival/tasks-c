#include <stdio.h>

int main() {
  int arr[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  int ch, mes, year, n;
  scanf("%d %d %d %d", &ch, &mes, &year, &n);
  ch += n;
  while (ch > arr[mes % 12]) {
    if (mes == 2){
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        ch -= 29;
        mes += 1;
      }
      else{
        ch -= 28;
        mes += 1;
      }
    }
    else if (mes == 12){
      ch -= arr[mes % 12];
      mes += 1;
      year += 1;
      mes = 1;
    }
    else{
      ch -= arr[mes % 12];
      mes += 1;
    }
  }
  if (ch == 0){
    ch = 29;
  }
  printf("%d %d %d\n", ch, mes, year);
  return 0;
}
