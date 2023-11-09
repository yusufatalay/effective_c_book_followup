#include <stdio.h>
#include <stdlib.h>
int main(void){
  FILE *fp = fopen("text.txt", "r");
  if (fp == NULL){
    fputs("Cannot open text.txt file\n", stderr );
    return EXIT_FAILURE;
  }

  if (fseek(fp,0 , SEEK_END ) != 0){
    fputs("Seek to the end of file failed\n", stderr );
    return EXIT_FAILURE;
  }

  long int fpi = ftell((fp));
  if (fpi == -1L){
    perror("Tell");
    return EXIT_FAILURE;
  }

  printf("file position = %ld\n", fpi);
  if (fclose(fp) == EOF){
    fputs("Failed to close file\n", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
} 
