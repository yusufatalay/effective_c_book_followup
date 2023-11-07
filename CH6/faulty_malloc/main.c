
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  char *str = (char *)malloc(16);

  if (str) {
    strncpy(str, "123456789abcdef", 15); 
    printf("str = %s\n", str); // malloc does not create zeroed values, so before printing anything the last place of the array sould be explicitly set to null terminator.
    // fixes possible error
    str[15] = '\0';
    free(str);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
