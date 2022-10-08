#include <stdio.h>
#define N 1001

int main(){
  double arr[N][N] = {0};
  int i, q, n, m;
  arr[0][0] = 1;
  for (i = 1; i < N; i++){
    arr[i][0] = 1;
    arr[i][i] = 1;
    for (int j = 2; j < i + 1; j++){
      arr[i][j - 1] = arr[i - 1][j - 2] + arr[i - 1][j - 1];
    }
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++){
    scanf("%d %d", &n, &m);
    printf("%0.10g\n", arr[n][m]);
  }
}
