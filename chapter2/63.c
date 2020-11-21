#include<stdio.h>

/* 高k位置 0 和 1 的问题 */

unsigned srl(unsigned x, int k) { // 高k位置0
  unsigned xsra = (int)x >> k;
  unsigned mask_code = (unsigned)(~0) << k >> k;
  return xsra & mask_code;
}

unsigned sra(int x, int k) { // 高k位置1，如果x是个负数的话
  unsigned xsrl = (unsigned)x >> k;
  int mask_code = x>>k;
  return xsrl | mask_code;
}

int main() {
  unsigned test_num = -213121;
  int test_num2 = -213121;
  unsigned l_result = srl(test_num, 1);
  unsigned a_result = sra(test_num2, 1);
  printf("luoji   %x\n", l_result);
  printf("suanshu %x\n", a_result);
  return 0;
}