#include <stdio.h>

void func1(void){
  puts("FUN1 invoked");
}

void func2(void){
  puts("FUN2 invoked");
}

void func3(void){
  puts("FUN3 invoked");
}

// array
void (*funcarr[3])() = {func1, func2, func3};

// funcinvoker
void invoker(int index){
  (funcarr[index])();
}

int main(void){
  invoker(0);

  invoker(2);

  invoker(1);

  return 0;
}
