#include <stdio.h>
#include <string.h>

void reverseplus(char *start, int len){
  char tmp;
  for (int i = 0; i < (len / 2); i++){
    tmp = start[i];
    start[i] = start[len - i - 1];
    start[len - i - 1] = tmp;
  }
  for (int i = 0; i < len; i++){
    start[i] -= '0';
  }
}

int main(){
  char a[1001] = {0}, b[1001] = {0};
  char res[2002] = {0};
  int lena, lenb, tmp, per = 0, i, j;
  scanf("%s", a);
  scanf("%s", b);
  lena = strlen(a);
  lenb = strlen(b);
  reverseplus(a, lena);
  reverseplus(b, lenb);
  for (i = 0; i < lenb; i++){
    for (j = 0; j < lena; j++){
      tmp = (b[i] * a[j] + per);
      res[i+j] += tmp % 10;
      per = tmp / 10;
      per += res[i+j] / 10;
      res[i+j] %= 10;
    }
    res[i + j] += per % 10;
    per = 0;
  }
  i = 2001;
  while (res[i] == 0) {
    i--;
  }
  for (int j = i; j >= 0; j--){
    printf("%d", res[j]);
  }
}
