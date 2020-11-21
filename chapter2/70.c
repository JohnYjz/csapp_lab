#include<stdio.h>
/* 这个题感觉有点无聊 */
int fits_bits(int x, int k) {
  int shift_val = (sizeof(int) << 3) - k;
  return ((x << shift_val) >> shift_val) == x;
}


int main() {
  int test_num = 0x12345678;
  int result1 = fits_bits(test_num, 4);
  printf("fits_bits1 %x\n", result1);
  return 0;
}