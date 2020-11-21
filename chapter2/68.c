#include<stdio.h>
#include <limits.h>

int lower_one_mask(int k) {
  /* 
  -1 = ff ff ff ff
  32 - 6 = 26;
  即 00 00 00 3f
   */
  int w = sizeof(int) << 3;
  return (unsigned)-1 >> (w - k);
}


int main() {
  int k = 6;
  int result = lower_one_mask(k);
  printf("lower_one_mask %x\n", result);
  return 0;
}