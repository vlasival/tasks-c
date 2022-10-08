#include <stdio.h>
#define LENGTH 256

int main(){
  int arr[LENGTH] = {0};
  unsigned char c;
  scanf("%c", &c);
  while (c != '.') {
    arr[c]++;
    scanf("%c", &c);
  }
  for (int i = 0; i < LENGTH; i++){
    if (arr[i] != 0){
      printf("'%c': %d\n", i, arr[i]);
    }
  }
  printf("%lu", sizeof(arr));
  return 0;
}
