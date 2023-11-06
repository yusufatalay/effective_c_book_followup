int m[2] = {1, 2};

int sum_m_elements(void) {
  int *pi;
  int j = 0;
  //                        |----------------> too far pointer (one past the last element)
  //                        v
  for (pi = &m[0]; pi < &m[2]; ++pi) {
    j += *pi;
  }
  return j;
}
