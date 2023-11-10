#include "isprime.h"
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


static void print_help(void) {
  printf("%s", "primetest num1 [num2 num3 ... numN]\n\n");
  printf("%s", "Tests positive integers for primality. Supports testing ");

  printf("%s [2-%llu].\n", "numbers in the range", ULLONG_MAX);
}

// Converts a string argument arg to an unsigned longlong value referenced by
// val. Returns true if the argument conversion succeeds, and false if it fails.
static bool convert_arg(const char *arg, unsigned long long *val) {
  char *end;
  // strtoll returns an in-band error indicator; clear errno before the call.
  errno = 0;
  *val = strtoull(arg, &end, 10);

  // Check for failures where the call returns a sentinel value and sets errno.
  if ((*val == ULLONG_MAX) && errno) {
    return false;
  }
  if (*val == 0 && errno) {
    return false;
  }
  if (end == arg) {
    return false;
  }

  // If we got here, we're able to convert the argument. However, we want to
  // allow only values greated then one, so we reject values <=1.
  if (*val <= 1) {
    return false;
  }

  return true;
}

static unsigned long long *convert_command_line_args(int argc, char *argv[], size_t *num_args) {
  *num_args = 0;
  if (argc <= 1) {
    // No command line arguments given
    print_help();
  }

  // We know the maximum number of arguments the user could have passed,
  // so allocate an array large enough to hold all of the elements. Subtract

  // one for the program name itself. If the allocation fails, treat it as a
  // faile conversion.
  unsigned long long *args =
      (unsigned long long *)malloc(sizeof(unsigned long long) * (argc - 1));

  bool failed_conversion = (args == NULL);

  for (int i = 1; i < argc && !failed_conversion; ++i) {
    // Attempt to convert the argument into an integer. If we couldn't convert
    // it, set failed_conversion to true.
    unsigned long long one_arg;
    failed_conversion |= !convert_arg(argv[i], &one_arg);
    args[i - 1] = one_arg;
  }

  if (failed_conversion) {
    // Free the array, print help and bail out
    free(args);
    print_help();
    return NULL;
  }

  *num_args = argc - 1;
  return args;
}

int main(int argc, char *argv[]){
  size_t num_args;

  unsigned long long *vals = convert_command_line_args(argc, argv, &num_args);

  if (!vals) return EXIT_FAILURE;

  for (size_t i = 0; i < num_args; ++i){
    printf("%llu is %s.\n" ,vals[i], is_prime(vals[i], 100) ? "probably prime" : "not prime");
  }

  free(vals);
  return EXIT_SUCCESS;
  
}

