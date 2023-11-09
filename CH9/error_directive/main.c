#if __STDC__ && __STDC_NO_THREADS__ != 1
  #include <threads.h>
#elif POSIX_THREADS == 200809L
  #include <pthread.h>
#else
  #error Neither <threads.h> nor <pthread.h> is available
#endif
  
