#include <stdio.h>
#include <stdlib.h>

int cmp(const void *i, const void *j) {
  return (*(int *)i - *(int *)j);
}


int difference(int* arr1, int* arr2, int* res, int n, int m){
  int i = 0, j = 0, cnt = 0, tmp;
  while((i < n) && (j < m)){
    if (arr1[i] < arr2[j]){
      if (res[cnt - 1] != arr1[i]){
        res[cnt++] = arr1[i];
      }
      i++;
    }
    else if (arr1[i] > arr2[j]){
      j++;
    }
    else{
      tmp = arr1[i];
      while(arr1[i] == tmp){
        i++;
      }
      while(arr2[j] == tmp){
        j++;
      }
    }
  }
  while (i < n){
    if (res[cnt - 1] != arr1[i]){
      res[cnt++] = arr1[i];
    }
    i++;
  }

  return cnt;
}

int main(){
  int n, m, k;

  scanf("%d", &n);
  int *arr1 = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &arr1[i]);
  }
  qsort(arr1, n, sizeof(int), cmp);

  scanf("%d", &m);
  int *arr2 = (int*)malloc(sizeof(int) * m);
  for (int i = 0; i < m; i++){
    scanf("%d", &arr2[i]);
  }
  qsort(arr2, m, sizeof(int), cmp);

  int* res = (int*)malloc(sizeof(int) * n);

  k = difference(arr1, arr2, res, n, m);

  printf("%d\n", k);
  for (int i = 0; i < k; i++){
    printf("%d ", res[i]);
  }
  free(arr1);
  free(arr2);
  free(res);
  return 0;
}
