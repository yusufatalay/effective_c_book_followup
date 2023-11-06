#include <stdio.h>

int glob; // static storage initialized to 0

int f(void){
  return glob+10;
}

int g(void){
  glob =42;
  return glob;
}

int max(int a, int b ) {
  if (a>b){
    return a;
  }else{
    return b;
  }
}

int main(void){
  
  int max_num = max(g(),f() ); // f is called first on my system

  printf("%d\n", max_num);
}
