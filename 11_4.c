#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int qarrcmp(const void *i, const void *j) {
  long long tmp = *(long long*)i - *(long long*)j;
  if (tmp > 0){
    return 1;
  }
  else if (tmp < 0){
    return -1;
  }
  else{
    return 0;
  }
}


int qstrcmp(const void *i, const void *j) {
  return strcmp(*(char**)i, *(char**)j);
}


int lower_bound(const void *input, const void *key, unsigned n, unsigned size, int (*cmp)(const void *, const void *)){
  char *arr = (char*)input;
  int tmp, l = 0, r = n - 1, mid;
  while(l < r){
    mid = (l + r) / 2;
    tmp = (*cmp)((void*)(arr + mid * size), key);
    if (tmp < 0){
      l = mid + 1;
    }
    else {
      r = mid;
    }
  }
  if ((*cmp)((void*)(arr + l * size), key) < 0){
    l++;
  }
  return l;
}

int main(){
  int n, m, q, p, res;
  scanf("%d", &n);
  long long *arr = malloc(sizeof(long long) * n);
  for (int i; i < n; i++){
    scanf("%lld", &arr[i]);
  }
  scanf("%d", &m);
  char **str = calloc(sizeof(char*), m);
  for (int i = 0; i < m; i++){
    str[i] = malloc(sizeof(char) * 32);
    scanf("%s", str[i]);
  }
  qsort(arr, n, sizeof(long long), qarrcmp);
  qsort(str, m, sizeof(char*), qstrcmp);

  scanf("%d", &q);
  long long tmp;
  for (int i = 0; i < q; i++){
    scanf("%lld", &tmp);
    res = lower_bound(arr, (void*)(&tmp), n, sizeof(long long), qarrcmp);
    printf("%d\n", res);
  }
  scanf("%d", &q);
  char *s = malloc(sizeof(char) * 32);
  for (int i = 0; i < q; i++){
    scanf("%s", s);
    res = lower_bound(str, &s, m, sizeof(char*), qstrcmp);
    printf("%d\n", res);
  }
  free(arr);
  for (int i = 0; i < m; i++){
    free(str[i]);
  }
  free(str);
  return 0;
}
