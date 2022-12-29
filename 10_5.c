#include <stdio.h>
#include <stdlib.h>


double sinus(double x){
  double result = 0, pw = x, tmp = 1;
  int s = 1;
  for(int i = 1; i < 30; i += 2) {
    tmp /= i;
    result += s * pw * tmp;
    tmp /= (i + 1);
    s = -s;
    pw = pw * x * x;
  }
  return result;
}

int main(){
  int n;
  double tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%lf", &tmp);
    tmp = sinus(tmp);
    printf("%0.15lf\n", tmp);
  }
}
