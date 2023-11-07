// TODO fix use-after-free defect

#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp){
  free(dirp->d_buf);
  close(dirp->d_fd); // in original version this close were called after free
  return free(dirp);
}
