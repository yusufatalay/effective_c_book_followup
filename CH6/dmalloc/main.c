#include <stdio.h>
#include <stdlib.h>
#ifdef DMALLOC
#include "dmalloc.h"
#endif

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
  free(msg);
  return;
}

int main(int argc, char *argv[]){
  if (argc != 3 && argc != 4){
    /* the error message won't be more than 80 chars*/
    char *errmsg = (char *)malloc(80);
    sprintf(errmsg,
      "Sorry %s,\nUsage: caesar secret_file keys_file [output_file]\n",
      getenv("USER"));    

    usage(errmsg);
    free(errmsg);
    exit(EXIT_FAILURE);
  }

  // more code
  exit(EXIT_SUCCESS);
}
