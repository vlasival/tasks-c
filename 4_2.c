#include <stdio.h>
#include <string.h>

void reverse(char *start, int len){
  char tmp;
  for (int i = 0; i < (len / 2); i++){
    tmp = start[i];
    start[i] = start[len - i - 1];
    start[len - i - 1] = tmp;
  }
}

int main(){
  int n, len, j = 0;
  char str[101];
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%s", str);
    j = strlen(str);
    reverse(str, j);
    printf("%s\n", str);
  }
  return 0;
}
