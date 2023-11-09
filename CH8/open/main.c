#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  const char *pathname = "/tmp/file";

  if ((fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1) {
    fprintf(stderr, "Can't open %s.\n", pathname);
    exit(1);
  }
  return 0;
}
