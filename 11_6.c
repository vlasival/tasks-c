#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get(char* str, double* c1, double* c2, double* c3){
  char* tmp = strtok(str, "O() ");
  while (tmp) {
    if (tmp[0] <= '9' && tmp[0] >= '0'){
      sscanf(tmp, "%lf^N", c1);
    }
    if (tmp[0] == 'N') {
      if (tmp[1] == '\0')
        *c2 = 1;
      else {
        sscanf(tmp, "N^%lf", c2);
      }
    }
    if (tmp[0] == 'l') {
      if (tmp[4] == '\0')
        *c3 = 1;
      else
        sscanf(tmp, "logN^%lf", c3);
    }
    tmp = strtok(NULL, "O() ");
  }
}


int res(double c1, double c2, double c3, double c4, double c5, double c6){
  if (c1 > c4){
    return 1;
  }
  if (c1 < c4){
    return -1;
  }
  if (c2 > c5){
    return 1;
  }
  if (c2 < c5){
    return -1;
  }
  if (c3 > c6){
    return 1;
  }
  if (c3 < c6){
    return -1;
  }
  return 0;
}


int main(){
  int n;
  scanf("%d\n", &n);
  char a[100];
  char b[100];
  for (int i = 0; i < n; i++){
    gets(a);
    gets(b);
    double c1 = 1, c2 = 0, c3 = 0, c4 = 1, c5 = 0, c6 = 0;
    get(a, &c1, &c2, &c3);
    get(b, &c4, &c5, &c6);
    // printf("%lf %lf %lf %lf %lf %lf\n", c1, c2, c3, c4, c5, c6);
    printf("%d\n", res(c1, c2, c3, c4, c5, c6));
  }
}
