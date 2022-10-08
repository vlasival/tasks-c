#include <stdio.h>
#define abs(a) \  // перенос строки в define
a > 0 ? a : (-a)

// НОД для unsigned
unsigned gcd_1 (int a, int b){
  if (a * b == 0){
    return a + b;
  }
  return (gcd_1(b, a % b));
}

typedef struct Rat {
  int num;
  unsigned den;
}R;

R mult(R a, R b){
  R res = {
    a.num * b.num,
    a.den * b.den
  };
  unsigned tmp = gcd_1(abs(res.num), res.den);
  res.num /= tmp;
  res.den /= tmp;
  return res;
};

 /*//НОД:
int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  else if (a == 0){
    return b;
  }
  else{
    gcd(b, a % b);
  }
}
*/

int main(){

}
