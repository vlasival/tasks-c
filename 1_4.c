#include <stdio.h>
#include <math.h>

int main(){
  int x, s, i = 2;
  scanf("%d", &x);
  if (x == 1){
    printf("%s\n", "NO");
    return 0;
  }
  else if (x == 2 || x == 3){
    printf("%s\n", "YES");
    return 0;
  }
  else{
    s = sqrt(x);
    s += 1;
    //printf("%d", s);

    while (i < s){
      if (x % i == 0){
        printf("%s\n", "NO");
        return 0;
      }
      else;
      i++;
    }
    printf("%s\n", "YES");
    return 0;
  }
}
