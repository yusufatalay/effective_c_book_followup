#include <stdio.h>

static unsigned int counter = 0;

void increment(void) {
  counter++;
  printf("%d ", counter);
}

// exercise
unsigned int retrieve(void) { return counter; }

int main(void) {
  for (int i = 0; i < 5; i++) {
    increment();
    return 0;
  }
}
