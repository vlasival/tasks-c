#include <stdio.h>

int main(){
  int ch, min, sec, d, temp;
  scanf("%d %d %d %d", &ch, &min, &sec, &d);
  temp = ch * 3600 + min * 60 + sec + d;
  ch = (temp / 3600);
  temp -= ch * 3600;
  ch %= 24;
  min = temp / 60;
  temp -= min * 60;
  printf("%d %d %d\n", ch, min, temp);
  return 0;
}
