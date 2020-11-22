#include <stdio.h>

/* 
允许溢出
 */
int mul3div4(int x) {
  int mul_result = (x << 1) + x;

  int shift_val = (sizeof(mul_result) << 3) - 1;
  int isNeg = ((mul_result >> shift_val) & 1) == 1;
  isNeg && (mul_result = (mul_result + (1 << 2) - 1));
  return mul_result >> 2;
}
int main() {
  printf("%d\n", mul3div4(-12345));
  printf("%d\n", mul3div4(-12345));
  printf("%d\n", mul3div4(12345));
  return 0;
}