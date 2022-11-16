#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000001

typedef struct s_List{
  char data[8];
  struct s_List *next;
}List;

int main(){
  List *starts[N];
  List *ends[N];
  List *m;
  int n, tmp;
  char str[8];
  for (int i = 0; i < N; i++){
    List *p = (List*)malloc(sizeof(List));
    p->next = NULL;
    starts[i] = p;
    ends[i] = p;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &tmp);
    scanf("%s", str);
    List *p = (List*)malloc(sizeof(List));
    strcpy(p->data, str);
    p->next = NULL;
    ends[tmp]->next = p;
    ends[tmp] = p;

  }
  for (int i = 0; i < N; i++){
    if (starts[i]->next != NULL){
      m = starts[i];
      while (m->next != NULL){
        printf("%d %s\n", i, m->next->data);
        m = m->next;
      }
    }
  }
}
