/*
设int为4个字节
sizeof(int) == 4
0100左移三位，即 0010 0000 = 32;
左移三位就是*8
*/

#include<stdio.h>

int every_bit_is_one(int x) {
  return x | ~0;
}

int every_bit_is_zero(int x) {
  return x & 0;
}

int lowest_byte_is_one(int x) {
  return x & 0xFF;
}

int highest_byte_is_zero(int x) {
  int shift_val = (sizeof(int) - 1) << 3;
  int mask_code = ~(0xFF << shift_val);
  return x & mask_code;
}

int main() {
  int test_num = 0x11223344;
  int result1 = every_bit_is_one(test_num);
  int result2 = every_bit_is_zero(test_num);
  int result3 = lowest_byte_is_one(test_num);
  int result4 = highest_byte_is_zero(test_num);
  printf("every_bit_is_one:     %x\n", result1);
  printf("every_bit_is_zero:    %x\n", result2);
  printf("lowest_byte_is_one:   %x\n", result3);
  printf("highest_byte_is_zero: %x\n", result4);
}