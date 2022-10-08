#include <stdio.h>
#include <string.h>


int main(){
  unsigned int str[127] = {0}, len;
  char c[100];
  while (gets(c)){
    len = strlen(c);
    for(int i = 0; i < len; i++)
      if (c[i] >= 32 && c[i] <= 126){
        str[(int)c[i]]++;
      }
  }

  for (int i = 32; i < 127; i++){
    if (str[i] != 0){
      printf("%c ", i);
      for (int j = 0; j < str[i]; j++){
        printf("#");
      }
      printf("\n");
    }
  }
}
