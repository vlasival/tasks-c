#include <stdio.h>

/*
struct Point {
  int x, y, z;
};

struct Point points[3];



int main(){
  points[1].x = 1;
  points[1].y = 2;
  points[1].z = 3;
  printf("%d %d %d", points[1].x, points[1].y, points[0].z);

}
*/
//решето эратосфена

int main(){
  int n;
  char prime[1000000] = {0};
  scanf("%d", &n);
  for (int i = 2; i * i < n; i++){
    if (prime[i] == 0){
      for (int j = i * i; j < n; j+=i){
        prime[j] = 1;
      }
    }
  }
  for (int i = 2; i < n; i++){
    if (prime[i] == 0){
      printf("%d ", i);
    }
  }
}

/* передача по указателю - небезопасно, функция может изменить данные.
защитить можно с помощью const

переименование типов - typedef int MyInt
MyInt a = 10;
int b = 12;
a + b = 22;

const int * const p3 = значение; - самый защищённый указатель

const int * p1
++p1 - Ok
++*p1  -  error

int * const p2
++p2  -  error
++*p2  -  ok
*/
