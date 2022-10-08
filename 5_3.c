#include <stdio.h>
#include <string.h>

typedef struct Label_s {
  char name[16]; //имя автора (заканчивается нулём) int age; //возраст автора (сколько лет)
  int age;
} Label;

typedef struct NameStats_s {
  int cntTotal; //сколько всего подписей
  int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s {
  int cntTotal; //сколько всего подписей
  int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
  int cntKids;//сколько подписей детей (меньше 14 лет)
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges){
  int nlen;
  for (int i = 0; i < cnt; i++){
    nlen = strlen(arr[i].name);
    if (nlen > 10){
      oNames->cntLong++;
    }
    if (arr[i].age >= 18){
      oAges->cntAdults++;
    }
    else if (arr[i].age < 14){
      oAges->cntKids++;
    }
  }
}

int main(){
  int n, i;
  Label arr[1000];
  NameStats names = {0, 0};
  AgeStats ages = {0, 0, 0};
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%s %d let", arr[i].name, &arr[i].age);
  }
  calcStats(arr, n, &names, &ages);
  names.cntTotal = n;
  ages.cntTotal = n;
  printf("names: total = %d\n", names.cntTotal);
  printf("names: long = %d\n", names.cntLong);
  printf("ages: total = %d\n", ages.cntTotal);
  printf("ages: adult = %d\n", ages.cntAdults);
  printf("ages: kid = %d", ages.cntKids);
}
