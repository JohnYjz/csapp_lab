#include <stdio.h>

/* 
x/(2^k) 即 x>>k

如果x < 0，要加上偏执，后才位移
x = x + (1 << k) - 1
 */
int divide_power2(int x, int k) {
  int shift_val = (sizeof(x) << 3) - 1;
  int isNeg = ((x >> shift_val) & 1) == 1;
  isNeg && (x = (x + (1 << k) - 1));
  return x >> k;
}
int main() {
  printf("%d\n", divide_power2(-12345, 1));
  printf("%d\n", divide_power2(-12345, 4));
  printf("%d\n", divide_power2(12345, 4));
  return 0;
}