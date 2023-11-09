#include <stdio.h>
#include <stdlib.h>
typedef struct sigrecord{
  int signum;
  char signame[10];
  char sigdesc[100];
}sigrecord;

int main(void){
  int status = EXIT_SUCCESS;
  FILE *fp;
  sigrecord sigrec;
  size_t size = sizeof(sigrec);

  if ((fp = fopen("signals.txt", "rb")) == NULL){
    fputs("Cannot open signals.txt file\n", stderr);
    return EXIT_FAILURE;
  }


  // read the second signal by using size as offset
  if (fseek(fp, size, SEEK_SET) != 0){
    fputs("fseek in signals.txt file failed\n", stderr);
    status = EXIT_FAILURE;
    goto close_files;
  }

  if (fread(&sigrec,size, 1, fp) != 1){
    fputs("Cannot read from signals.txt file \n", stderr);
    status = EXIT_FAILURE;
    goto close_files;
  }

  printf("Signal\n number = %d\n name = %s\n description = %s\n\n", sigrec.signum, sigrec.signame, sigrec.sigdesc);

close_files:
  fclose(fp);
  return status;
}
