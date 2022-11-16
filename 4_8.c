#include <stdio.h>

typedef struct Fragment{
  unsigned int count, value;
} Fragment;

int getlenght (int a){
  int i = 0;
  if (a == 0){
    return 1;
  }
  while (a != 0){
    a /= 10;
    i++;
  }
  return i;
}

void table(const Fragment *arr, int m1, int m2, int m3){
  char str[30] = {0};
  short ind = 2, temp;
  str[0] = '+';
  str[1] = '-';
  for (int j = 0; j < m1; j++){
    str[ind++] = '-';
  }
  str[ind++] = '-';
  str[ind++] = '+';
  str[ind++] = '-';
  for (int j = 0; j < m2; j++){
    str[ind++] = '-';
  }
  str[ind++] = '-';
  str[ind++] = '+';
  str[ind++] = '-';
  for (int j = 0; j < m3; j++){
    str[ind++] = '-';
  }
  str[ind++] = '-';
  str[ind++] = '+';

  printf("%s\n", str);
  for (int i = 0; i < 1001; i++){
    if (arr[i].count > 0){
      printf("| ");
      temp = m1 - getlenght(i);
      for (int j = 0; j < temp; j++){
        printf(" ");
      }
      printf("%d", i);
      printf(" | ");
      temp = m2 - getlenght(arr[i].count);
      for (int j = 0; j < temp; j++){
        printf(" ");
      }
      printf("%d", arr[i].count);
      printf(" | ");
      temp = m3 - getlenght(arr[i].value);
      for (int j = 0; j < temp; j++){
        printf(" ");
      }
      printf("%d", arr[i].value);
      printf(" |\n");
      printf("%s\n", str);
    }
  }
}

int main(){
  int num, m1 = 0, m2 = 0, m3 = 0, tmp1, tmp2, t;
  Fragment arr[1002] = {0};
  scanf("%d", &num);
  for (int i = 0; i < num; i++){
    scanf("%d %d", &tmp1, &tmp2);
    arr[tmp1].count += 1;
    arr[tmp1].value += tmp2;
    t = getlenght(tmp1);
    m1 = t > m1 ? t : m1;
    t = getlenght(arr[tmp1].count);
    m2 = t > m2 ? t : m2;
    t = getlenght(arr[tmp1].value);
    m3 = t > m3 ? t : m3;
  }
  table(arr, m1, m2, m3);
}
