#include <stdlib.h>

int main(void) {

  void *p2;
  void *p = malloc(100);
  int newSize = 200;

  if ((p2 = realloc(p, newSize)) == NULL) {

    free(p);
    return NULL;
  }

  p = p2; 
  // NOTE: declare new same-type pointer to hold the increased or shrinked value, because when realloc succeeds it frees the old pointer and returns new one
  // if it fails it returns NULL, (p = relloc(p, newSize)) would resultint p to NULL if realloc fails)

  
}
