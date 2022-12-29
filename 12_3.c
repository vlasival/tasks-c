#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ActorBio_n {
  char name[31];
  int year;
  char country[11];
} ActorBio;

typedef struct ActorInMove_n {
  char name[31];
  char movie[21];
} ActorInMove;



int main(){
  int n, q;
  char tmp;
  int cnt;
  scanf("%d", &n);
  ActorBio *arr1 = malloc(sizeof(ActorBio) * n);
  for (int i = 0; i < n; i++){
    cnt = 0;
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    while(tmp != '"'){
      arr1[i].name[cnt] = tmp;
      scanf("%c", &tmp);
      cnt++;
    }
    arr1[i].name[cnt] = 0;
    scanf("%d", &arr1[i].year);
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    cnt = 0;
    while(tmp != '"'){
      arr1[i].country[cnt] = tmp;
      scanf("%c", &tmp);
      cnt++;
    }
    arr1[i].country[cnt] = 0;
  }

  scanf("%d", &q);
  ActorInMove *arr2 = malloc(sizeof(ActorInMove) * q);
  for (int i = 0; i < q; i++){
    cnt = 0;
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    while(tmp != '"'){
      arr2[i].name[cnt] = tmp;
      scanf("%c", &tmp);
      cnt++;
    }
    arr2[i].name[cnt] = 0;
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    scanf("%c", &tmp);
    cnt = 0;
    while(tmp != '"'){
      arr2[i].movie[cnt] = tmp;
      scanf("%c", &tmp);
      cnt++;
    }
    arr2[i].movie[cnt] = 0;
  }


  for (int i = 0; i < n; i++){
    for (int j = 0; j < q; j++){
      if (strcmp(arr1[i].name, arr2[j].name) == 0){
        printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n", arr1[i].name, arr1[i].year, arr1[i].country, arr2[j].name, arr2[j].movie);
      }
    }
  }

}
