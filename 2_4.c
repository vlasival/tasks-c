#include <stdio.h>

int max(int a, int b){
  return (a >= b ? a : b);
}

int min(int a, int b){
  return(a > b ? b : a);
}

int main(){
  int a1, a2, b1, b2, c1, c2;
  scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
  if (a1 * a2 < b1 * b2 + c1 * c2){
    printf("NO");
    return 0;
  }
  else {
    if (min(a1, a2) >= max(b1, b2) + max(c1, c2)){
      if (max(a1, a2) >= max(min(b1, b2), min(c1, c2))) {
        printf("YES");
        return 0;
      }
    }
    if (min(a1, a2) >= min(b1, b2) + max(c1, c2)) {
      if (max(a1, a2) >= max(max(b1, b2), min(c1, c2))) {
        printf("YES");
        return 0;
      }
    }
    if (min(a1, a2) >= max(b1, b2) + min(c1, c2)){
      if (max(a1, a2) >= max(min(b1, b2), max(c1, c2))) {
        printf("YES");
        return 0;
      }
    }

    if (min(a1, a2) >= min(b1, b2) + min(c1, c2)){
      if (max(a1, a2) >= max(max(b1, b2), max(c1, c2))) {
        printf("YES");
        return 0;
      }
    }

    if (max(a1, a2) >= max(b1, b2) + max(c1, c2)){
      if (min(a1, a2) >= max(min(b1, b2), min(c1, c2))) {
        printf("YES");
        return 0;
      }
    }
    if (max(a1, a2) >= min(b1, b2) + max(c1, c2)) {
      if (min(a1, a2) >= max(max(b1, b2), min(c1, c2))) {
        printf("YES");
        return 0;
      }
    }

    if (max(a1, a2) >= max(b1, b2) + min(c1, c2)){
      if (min(a1, a2) >= max(min(b1, b2), max(c1, c2))){
        printf("YES");
        return 0;
      }
    }

    if (max(a1, a2) >= min(b1, b2) + min(c1, c2)){
      if (min(a1, a2) >= max(max(b1, b2), max(c1, c2))) {
        printf("YES");
        return 0;
      }
    }
  }
  printf("NO");
  return 0;
}
