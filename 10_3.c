#include <stdio.h>
#include <stdlib.h>

void headHead(int *from, int *to, int *top1, int *top2, int *bot1, int *bot2, int *sizeA, int *sizeB, int n){
  *top2 = *top2 - 1 < 0 ? 2 * n : *top2 - 1;
  to[*top2] = from[*top1];
  from[*top1] = 0;
  *top1 = (*top1 + 1) % (2 * n + 1);
  *sizeA -= 1;
  *sizeB += 1;
}

void headBottom(int *from, int *to, int *top1, int *top2, int *bot1, int *bot2, int *sizeA, int *sizeB, int n){
  *bot2 = (*bot2 + 1) % (2 * n + 1);
  to[*bot2] = from[*top1];
  from[*top1] = 0;
  *top1 = (*top1 + 1) % (2 * n + 1);
  *sizeA -= 1;
  *sizeB += 1;
}

void bottomBottom(int *from, int *to, int *top1, int *top2, int *bot1, int *bot2, int *sizeA, int *sizeB, int n){
  *bot2 = (*bot2 + 1) % (2 * n + 1);
  to[*bot2] = from[*bot1];
  from[*bot1] = 0;
  *bot1 = *bot1 - 1 < 0 ? 2 * n : *bot1 - 1;
  *sizeA -= 1;
  *sizeB += 1;
}

void bottomHead(int *from, int *to, int *top1, int *top2, int *bot1, int *bot2, int *sizeA, int *sizeB, int n){
  *top2 = *top2 - 1 < 0 ? 2 * n : *top2 - 1;
  to[*top2] = from[*bot1];
  from[*bot1] = 0;
  *bot1 = *bot1 - 1 < 0 ? 2 * n : *bot1 - 1;
  *sizeA -= 1;
  *sizeB += 1;
}

int main(){
  int n, q, tmp;
  scanf("%d", &n);
  scanf("%d", &q);


  int *a = malloc(sizeof(int) * (2 * n + 1));
  int *b = malloc(sizeof(int) * (2 * n + 1));
  int top1 = 0, top2 = 0, bot1 = n - 1, bot2 = n - 1, sizeA = n, sizeB = n;
  for(int i = 0; i < n; i++){
    a[i] = i + 1;
    b[i] = -1 - i;
  }

  if (q > 0){
    for(int i = 0; i < q; i++){
      scanf("%1x", &tmp);
      if (tmp == 0 || tmp == 5 || tmp == 10 || tmp == 15){
        continue;
      }
      switch (tmp) {
        case 1:
          if (sizeA == 0){
            break;
          }
          headBottom(a, a, &top1, &top1, &bot1, &bot1, &sizeA, &sizeA, n);
          break;
        case 2:
          if (sizeA == 0){
            break;
          }
          headHead(a, b, &top1, &top2, &bot1, &bot2, &sizeA, &sizeB, n);
          break;
        case 3:
          if (sizeA == 0){
            break;
          }
          headBottom(a, b, &top1, &top2, &bot1, &bot2, &sizeA, &sizeB, n);
          break;
        case 4:
          if (sizeA == 0){
            break;
          }
          bottomHead(a, a, &top1, &top1, &bot1, &bot1, &sizeA, &sizeA, n);
          break;
        case 6:
          if (sizeA == 0){
            break;
          }
          bottomHead(a, b, &top1, &top2, &bot1, &bot2, &sizeA, &sizeB, n);
          break;
        case 7:
          if (sizeA == 0){
            break;
          }
          bottomBottom(a, b, &top1, &top2, &bot1, &bot2, &sizeA, &sizeB, n);
          break;
        case 8:
          if (sizeB == 0){
            break;
          }
          headHead(b, a, &top2, &top1, &bot2, &bot1, &sizeB, &sizeA, n);
          break;
        case 9:
          if (sizeB == 0){
            break;
          }
          headBottom(b, a, &top2, &top1, &bot2, &bot1, &sizeB, &sizeA, n);
          break;
        case 11:
          if (sizeB == 0){
            break;
          }
          headBottom(b, b, &top2, &top2, &bot2, &bot2, &sizeB, &sizeB, n);
          break;
        case 12:
          if (sizeB == 0){
            break;
          }
          bottomHead(b, a, &top2, &top1, &bot2, &bot1, &sizeB, &sizeA, n);
          break;
        case 13:
          if (sizeB == 0){
            break;
          }
          bottomBottom(b, a, &top2, &top1, &bot2, &bot1, &sizeB, &sizeA, n);
          break;
        case 14:
          if (sizeB == 0){
            break;
          }
          bottomHead(b, b, &top2, &top2, &bot2, &bot2, &sizeB, &sizeB, n);
          break;
      }
    }
  }

  printf("%d ", sizeA);
  tmp = top1;
  for (int i = 0; i < sizeA; i++){
    printf("%d ", a[tmp]);
    tmp = (tmp + 1) % (2 * n + 1);
  }
  printf("\n");

  printf("%d ", sizeB);
  tmp = top2;
  for (int i = 0; i < sizeB; i++){
    printf("%d ", b[tmp]);
    tmp = (tmp + 1) % (2 * n + 1);
  }
  printf("\n");
}
