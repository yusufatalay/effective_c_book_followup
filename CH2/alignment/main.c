#include <limits.h>
struct S{
  int i;
  double d;
  char c;
};

int main(void){
  unsigned char bad_buf[sizeof(struct S)];
  _Alignas(struct S ) unsigned char good_buf[sizeof(struct S)];

  struct S *bad_s_ptr = (struct S *)bad_buf;        // wrong pointer alignment

  struct S *good_s_ptr = (struct S *)good_buf;     // correct pointer alignmentgoogood_buf;     // correct pointer alignment
}
