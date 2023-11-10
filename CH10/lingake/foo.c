void func(int i){ // Implicit external linkage
  // i has no linkage
}

static void bar(void); // Internal linkage, different bar than bar.c
extern void bar(void){
  // bar still has internal linkage because the initial declaration was
  // declared as static; the extern specifier has no effect in this case.
}
