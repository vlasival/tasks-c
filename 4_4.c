#include <stdio.h>
#include <string.h>


void calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt, int *len){
  *len = strlen(iStr);
  for (int i = 0; i < *len; i++){
    if (iStr[i] - '0' >= 0 && iStr[i] - '0' <= 9){
      (*oDigitsCnt)++;
    }
    else if (iStr[i] >= 65 && iStr[i] <= 90){
      (*oUpperCnt)++;
    }
    else if (iStr[i] >= 97 && iStr[i] <= 122){
      (*oLowerCnt)++;
    }
  }
}

int main(){
  char s[101];
  int low, up, dig, i = 1, len;
  while (gets(s)){
    low = 0;
    up = 0;
    dig = 0;
    calcLetters(s, &low, &up, &dig, &len);
    printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", i, len, low + up, low, up, dig);
    i++;
  }
}
