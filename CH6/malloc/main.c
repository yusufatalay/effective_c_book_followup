#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char c[10];
  int i;
  double d;
} widget;

int main(void) {
  widget *p = malloc(sizeof(widget));

  if (p == NULL) {
    // Allocation error
    perror("Allocation error");
  }

  widget w = {"abc", 9, 3.14};
  memcpy(p, &w, sizeof(widget));
  printf("p.i = %d.\n", p->i);

  free(p);
}
