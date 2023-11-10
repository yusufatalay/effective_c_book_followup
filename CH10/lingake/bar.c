extern void func(int i); // Explicit external linkage

static void bar(void){ // Internal linkage; different bar than foo.c
  func(12); // Calls function from foo.c
  }

int i ; // External linkage; does not conflict with i from foo.c or bar.co
void baz(int k){ // implicit external linkage
  bar(); // Calls bar from bar.c not foo.c
  
}

  
