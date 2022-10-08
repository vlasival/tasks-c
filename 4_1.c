#include <stdio.h>

int printTime(int h, int m, int s){
  printf("%02d:%02d:%02d\n", h, m, s);
  return 0;
}

int main(){
  int n, h, m, s;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d %d %d", &h, &m, &s);
    printTime(h, m, s);
  }
  return 0;
}
