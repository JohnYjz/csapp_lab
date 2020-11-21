#include<stdio.h>

int int_shifts_are_arithmetic() {
  int test_num = -1;
  int test_res = test_num >> 1;
  int shift_val = (sizeof(int)<<3) - 1;
  int mask_code = 1 << shift_val;
  /* 
  res与mask_code做与运算，如果res最高位为0，则结果为0。否则不为0就是算数位
  */
 return !!(test_res & mask_code);
}


int main() {
  int is_arithmetic = int_shifts_are_arithmetic();
  printf("int_shifts_are_arithmetic:     %d\n", is_arithmetic);
  return 0;
}