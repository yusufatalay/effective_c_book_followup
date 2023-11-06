// TODO: Change the find_element to return the position of the key in a. Don't forget to return an error indication if the key is not found.
#include <stddef.h>
#include <stdio.h>

size_t find_element(size_t len, int arr[len], int key){
  size_t pos = (size_t)-1;

  // traverse arr and search for key
  for (size_t i = 0; i < len ; ++i){
    if (arr[i] == key){
      pos = i;
      break; 
    }
  }

  if (pos == (size_t) -1){
    perror("Key is not located in the arr");
  }

  return pos;
}
