#include<stdio.h>

unsigned rotate_left(unsigned x, int k) {
  int len = sizeof(unsigned) << 3;
  int right_shift_val = len - k;
  printf("len is %d , k is %d, result is %d\n", len, k, right_shift_val);
  unsigned high_bits = x >> right_shift_val;
  printf("high_bits %x\n", high_bits);
  unsigned low_bits = x << k;
  printf("low_bits %x\n", low_bits);
  return low_bits | high_bits;
}


int main() {
  unsigned test_num = 0x12345678;
  unsigned result1 = rotate_left(test_num, 4);
  printf("rotate_left1 %x\n", result1);
  unsigned result2 = rotate_left(test_num, 20);
  printf("rotate_left2 %x\n", result2);
  return 0;
}