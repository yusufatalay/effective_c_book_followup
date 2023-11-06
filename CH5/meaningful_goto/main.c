#include <stdio.h>
#include <stdlib.h>

// book forgots about this
typedef void object_t;

int do_something(void) {
  FILE *file1, *file2;
  object_t *obj;
  int ret_val = 0; // Initially assume a successful return value

  file1 = fopen("a_file", "w");
  if (file1 == NULL) {
    ret_val = -1;
    goto FAIL_FILE1;
  }

  file2 = fopen("another_file", "w");
  if (file2 == NULL) {
    ret_val = -1;
    goto FAIL_FILE2;
  }

  obj = malloc(sizeof(object_t));
  if (obj == NULL){
    ret_val = -1;
    goto FAIL_OBJ;
  }

  // Operate on allocated resources

  // Cleanup everything
  free(obj);

  FAIL_OBJ: // otherwise, close only the resource we opened
    fclose(file2);
  FAIL_FILE2:
    fclose(file1);
  FAIL_FILE1:
    return ret_val;

  
}
