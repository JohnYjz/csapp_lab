#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
  unsigned sign_f = (f >> 31) & 0x1;
  unsigned mask_code1 = ((~sign_f) & 0x1) << 31;
  return f & 0x7FFFFFFF | mask_code1;
}

int main () {
  printf("%x\n", float_negate(0xFFEEFFEE));
  printf("%x\n", float_negate(0x7FEEFFEE));
}