#include <stdio.h>

int main(){
  int a, kv, pod, e, etaj, i, res1, res2, temp;
  scanf("%d\n%d %d %d %d", &a, &kv, &pod, &e, &etaj);
  i = (kv - 1) / (etaj * (pod - 1) + e) + 1;
  temp = (a - 1) / i + 1;
  res1 = (temp - 1) / etaj + 1;
  res2 = (temp - 1) % etaj + 1;
  printf("%d %d\n", res1, res2);
  return 0;
}
