#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct DateTime_s {
  int year, month, day;
  int hours, minutes, seconds;
} DateTime;

void toChar(const DateTime *arr, char *str){
  int tmp1, i;
  tmp1 = (*arr).year;
  for (i = 0; i < 4; i++){
    str[3 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  tmp1 = (*arr).month;
  for (i = 0; i < 2; i++){
    str[5 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  tmp1 = (*arr).day;
  for (i = 0; i < 2; i++){
    str[7 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  tmp1 = (*arr).hours;
  for (i = 0; i < 2; i++){
    str[9 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  tmp1 = (*arr).minutes;
  for (i = 0; i < 2; i++){
    str[11 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  tmp1 = (*arr).seconds;
  for (i = 0; i < 2; i++){
    str[13 - i] = tmp1 % 10 + '0';
    tmp1 /= 10;
  }
  str[14] = 0;
}

DateTime min(const DateTime *arr, int cnt){
  char m[15] = {127}, str[15] = {0};
  int i;
  for (i = 0; i < cnt; i++){
    toChar(&arr[i], str);
    if (strcmp(m, str) > 0){
      strcpy(m, str);
    }
  }
  DateTime res = {0, 0, 0, 0, 0, 0};

  for (i = 0; i < 4; i++){
    res.year += (m[3 - i] - '0') * (int)pow(10, i);
  }
  for (i = 0; i < 2; i++){
    res.month += (m[5 - i] - '0') * (int)pow(10, i);
  }
  for (i = 0; i < 2; i++){
    res.day += (m[7 - i] - '0') * (int)pow(10, i);
  }
  for (i = 0; i < 2; i++){
    res.hours += (m[9 - i] - '0') * (int)pow(10, i);
  }
  for (i = 0; i < 2; i++){
    res.minutes += (m[11 - i] - '0') * (int)pow(10, i);
  }
  for (i = 0; i < 2; i++){
    res.seconds += (m[13 - i] - '0') * (int)pow(10, i);
  }

  return res;
}

int main(){
  int n;
  char str[15] = {0};
  DateTime arr[50000], res;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d %d %d %d %d %d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes, &arr[i].seconds);
  }
  res = min(arr, n);
  printf("%d %d %d %d %d %d", res.year, res.month, res.day, res.hours, res.minutes, res.seconds);
}
