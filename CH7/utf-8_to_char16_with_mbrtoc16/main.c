#include <bits/types/mbstate_t.h>
#include <locale.h>
#include <stddef.h>
#include <uchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#if __STDC_UTF_16__ != 1
#error "__STDC_UTF_16__ not defined" 
#endif

int main(void){
  setlocale(LC_ALL, "en_US.utf8");
  char input[] = u8"I♥️🐵s";
  const size_t input_size = sizeof(input);
  char16_t output[input_size]; // UTF-16 requires less code units than UTF-8

  char *p_input = input;
  char *p_end = input + input_size;
  char16_t *p_output = output;
  size_t code;
  mbstate_t state = {0};
  puts(input);

  while(code == mbrtoc16(p_output, p_input ,p_end-p_input , &state  )){
    if (code == (size_t) -1){
      break; // -1 - invalid code unit sequence detected
    }else if (code == (size_t) - 2) {
      break; // -2 - code unit sequence missing elements
    }else if (code == (size_t) -3){
      p_output++; // one value was written out
      p_input += code; // code is the number of code units read by function
    }
  }
  size_t output_size = p_output - output +1;
  printf("Converted to %zu UTF-16 code units: [ ", output_size);
  for(size_t x =0; x < output_size; ++x) {
    printf("%#x ", output[x]);
  }
  puts("]");

  
}
