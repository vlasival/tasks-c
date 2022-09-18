#include <stdio.h>

int main(){
  char a[3];
  scanf("%s", a);
  if (a[0] == 'M'){
    printf("1\n");
  }
  else if (a[0] == 'W'){
    printf("3\n");
  }
  else if (a[0] == 'F'){
    printf("5\n");
  }
  else if (a[0] == 'T'){
    if (a[1] == 'u'){
      printf("2\n");
    }
    else{
      printf("4\n");
    }
  }
  else{
    if (a[1] == 'a'){
      printf("6\n");
    }
    else{
      printf("7\n");
    }
  }
}
