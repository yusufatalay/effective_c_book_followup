#include <limits.h>
#include <stdio.h>


int main(void){
  
unsigned int ui = UINT_MAX;

ui++;

printf("ui = %u\n", ui); // wraparound to 0

ui--;

printf("ui = %u\n", ui); // return back to original value

return 0;
  
}
