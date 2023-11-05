#include <stdio.h>

void swap(int*, int*);

int main(void) {
  int a = 21;
  int b = 17;

  swap(&a, &b);
  printf("main: a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int *ap, int *bp) {
  int t = *ap;
  *ap = *bp;
  *bp = t;
  return;
}
