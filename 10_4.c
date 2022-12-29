#include <stdio.h>
#include <stdlib.h>


int main(){
  int n, tmp;
  scanf("%d", &n);
  char **arr = malloc(sizeof(char*) * n);
  for (int i = 0; i < n; i++){
    char *new = malloc(sizeof(char) * n);
    arr[i] = new;
    for(int j = 0; j < n; j++){
      scanf("%1d", &tmp);
      new[j] = (char)tmp;
      if (i == j){
        new[j] = 1;
      }
    }
  }

  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
      }
    }
  }
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%d", arr[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < n; i++){
    free(arr[i]);
  }
  free(arr);
  return 0;
}
