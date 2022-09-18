#include <stdio.h>

int main(){
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  if (x <= 0) printf("%d\n", -1);
  else if (y <= 0) printf("%d\n", -2);
  else if (z <= 0) printf("%d\n", -3);
  else printf("%d\n", x*y*2 + x*z*2 + y*z*2);
  return 0;
}
