#include <stdio.h>
#include <stdlib.h>

int main(void){
  // THIS code will crash, a FILE object should never be copied, 
  FILE my_stdout = *stdout;
  if (fputs("HELLO, WORLD!\n", &my_stdout )== EOF){
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
