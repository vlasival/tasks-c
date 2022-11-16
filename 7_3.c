#include <stdio.h>

typedef union Number{
  unsigned long long ll;
  double d;
} Num;

int main(){
  int n;
  unsigned short p, q;
  unsigned long long tmp;
  Num value;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%hd/%hd xor %llx", &p, &q, &tmp);
    value.d = (double)(p) / (double)(q);
    value.ll = value.ll ^ tmp;
    printf("%0.15g\n", value.d);
  }
}
