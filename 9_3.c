#include <stdio.h>
#include <stdlib.h>

int cmp(const void *i, const void *j) {
  return (*(int *)i - *(int *)j);
}

int main() {
  int n;
  scanf("%d", &n);
  if (n == 1){
    scanf("%d", &n);
    printf("%d\n", n);
    return 0;
  }
  long long res = 0;
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), cmp);
  for (int i = 0; i < n - 1; i++) {
    res += (long long)((long long)arr[i] * (long long)(n - i - 1));
  }
  printf("%lld\n", res);
  free(arr);
  return 0;
}
