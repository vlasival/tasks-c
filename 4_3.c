
#include <stdio.h>
#include <string.h>
char* concat(char *prev, char *post){
  int len = strlen(prev);
  while (*post != '\0'){
    *(prev++ + len) = *post++;
  }
  *(prev + len) = '\0';
  return prev + len;
}

int main(){
  int n, p;
  char a[1000000], b[101];
  scanf("%d", &n);
  scanf("%s", a);
  for (int i = 0; i < n - 1; i++){
    scanf("%s", b);
    concat(a, b);
  }
  printf("%s\n", a);
}
