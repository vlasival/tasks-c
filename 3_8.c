#include <stdio.h>
#include <math.h>

int main(){
  int p, q, i = 0, res = 0, a = 0, tmp;
  char n[32], r[32] = {0};

  scanf("%d %d %s", &p, &q, n);
  //scanf("%s", n);
  if (n[0] == '0'){
    printf("%c", '0');
    return 0;
  }
  while (n[i] != '\0'){
    i++;
  }
  for (int g = 0; g < i; g++){
    if (n[g] >= 'a'){
      tmp = n[g] - 'a' + 10;
    }
    else{
      tmp = n[g] - '0';
    }
    res += tmp * (int)pow(p, (i - g - 1));
  }
  a = 0;
  while (res >= q){
    r[a] = res % q;
    res = res / q;
    a++;
  }
  r[a] = res;
  for (int j = 0; j < a + 1; j++){
    if (r[a - j] >= 10){
      printf("%c", r[a - j] + 'a' - 10);
    }
    else{
      printf("%c", r[a - j] + '0');
    }
  }
  return 0;
}
