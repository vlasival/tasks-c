#include <stdio.h>

typedef struct student{
  char surname[30];
  int group;
  unsigned char marks[10];
}stud;

int comp (stud a, stud b){
  if (a.group > b.group){
    return 1;
  }
  else if (a.group < b.group){
    return (-1);
  }
  else {
    int res;
    for (int i = 0; i < 10; i++){
      res = res + a.marks[i] - b.marks[i];
    }
    if (res > 0){
      return 1;
    }
    else if (res < 0){
      return (-1);
    }
    else{
      return 0;
    }
  }
}
