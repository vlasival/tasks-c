#include <stdio.h>
#include <string.h>

void counter(char* s, int len){
  int n = 0;
  for (int i = 0; i < len; i++){
    if (s[i] >= 65 && s[i] <= 90){
      n++;
    }
  }
  printf("%d/%d ", n, len);
  for (int i = 0; i < len; i++){
    printf("%c", s[i]);
  }
  printf("\n");
}

int main(){
  char s[1000000], c;
  int j = 0, p = 0;
  scanf("%c", &c);
  while (c != '\n' && c != '\0'){
    while (c != '.' && c != ',' && c != ':' && c != ';'){
      s[j] = c;
      p = 1;
      j++;
      scanf("%c", &c);
      if (c == '\n' || c == '\0'){
        counter(s, j);
        return 0;
      }
    }
    if (p == 1){
      counter(s, j);
      p = 0;
      j = 0;
      strcpy(s, "");
    }
    scanf("%c", &c);
  }
  return 0;
}
