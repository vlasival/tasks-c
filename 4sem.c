#include <stdio.h>
#include <string.h>

int countapple(char *s){
  int i = 0;
  scanf("%s", s);
  while (strcmp(s, "end") != 0){
    if (strcmp(s, "apple") == 0){
      i++;
    }
    scanf("%s", s);
  }
  return (i);
}

int polyndrom(char *s){
  int a = 0, b = strlen(s) - 1;
  while (a < b){
    if (s[a] == ' '){
      a++;
    }
    else if (s[b] == ' '){
      b++;
    }
    if (s[a] != s[b]){
      return 0;
    }
    else{
      a++;
      b++;
    }
  }
  return 1;
}

int substr(char *s, char *a){
  int len1 = strlen(s), len2 = strlen(a);
  if (len1 < len2){
    return (-1);
  }
  int i, j, p = 0;
  for (i = 0; i < len1; i++){
    for (j = 0; j < len2; j++){
      if (s[i + j] == a[j]){
        continue;
      }
      else{
        break;
      }
    }
    if (j == len2){
      return i;
    }
  }
  return (-1);
}

int main(){
  char s[100], a[100];
  scanf("%s\n", s);
  scanf("%s", a);
  printf("%d\n", substr(s, a));
}
