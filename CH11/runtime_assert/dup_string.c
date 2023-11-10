#include <assert.h>
#include <stddef.h>
void *dup_string(size_t size, char *str) {
  assert(size <= LIMIT);
  // can also add string literal for more context
  assert(str != NULL && "str cannot be null");
}
