#include <stdio.h>
#include <stdlib.h>

int binsearch(int *arr, int l, int r, int elem){
  int mid = (l + r) / 2;
  while(r > l + 1){
    if (elem > arr[mid]){
      l = mid;
      mid = (r + mid) / 2;
    }
    else{
      r = mid;
      mid = (l + mid) / 2;
    }
  }
  return ((elem - arr[l]) > (arr[r] - elem) ? r : l);
}

int main(){
  int n, q, tmp, src;
  scanf("%d", &n);
  int *arr = malloc(sizeof(int) * n);
  int *p = malloc(sizeof(int) * (n - 1));
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < n - 1; i++){
    p[i] = arr[i + 1] - arr[i];
  }
  free(arr);

  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%d", &tmp);
    tmp = -tmp;
    src = binsearch(p, 0, n - 2, tmp);
    if (p[src] < tmp){
        src++;
    }
    printf("%d\n", src);
  }
  free(p);
  return 0;
}
