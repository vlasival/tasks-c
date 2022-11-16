#include <stdio.h>
#define N 100000

typedef struct List{
  double value;
  int next;
}List;

void printlist(const List *arr, int ind){
  while (arr[ind].next != -1) {
    printf("%0.3lf\n", arr[ind].value);
    ind = arr[ind].next;
  }
  printf("%0.3lf\n", arr[ind].value);
}
int main(){
  List arr[N];
  int n, ind;
  scanf("%d %d", &n, &ind);
  for (int i = 0; i < n; i++){
    scanf("%lf", &arr[i].value);
    scanf("%d", &arr[i].next);
  }
  printlist(arr, ind);
}
