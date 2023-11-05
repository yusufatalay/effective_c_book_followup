#include <stdio.h>

int j; // file scope of j begins

void f(int i) { // block scope of i begins
  int j = 1;    // block scope of j begins, hides file scope j
  i++;
  for (int i = 0; i < 2; i++) { // block scope of loop local i begins
    int j = 2;
    printf("%d\n", j); // inner j is in scope prints 2
  }
  printf("%d\n",j); // the outer j is in scope, prints 1
}

void g(int j); // j has function prototype scope; hides file scope j
  
