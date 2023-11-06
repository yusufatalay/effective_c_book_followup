#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int si1, si2, sresult;
  unsigned int ui1, ui2, uresult;

  if ((si2 < 0) || (si2 >= sizeof(int) * CHAR_BIT)) {
    puts("error signed");
  } else {
    sresult = si1 >> si2;
  }

  if (ui2 >= sizeof(unsigned int) * CHAR_BIT) {
    puts("error unsigned");
    return EXIT_FAILURE;
  } else {
    uresult = ui1 >> ui2;
  }
}
