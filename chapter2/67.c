#include<stdio.h>

/* SUN的int如果超过32位，那么结果就是错的 */
/* 对于机器而言，要保证位移小于最大位数 */

int int_size_is_32() {
  unsigned test_num = (unsigned)(-1);
  int is_32 = test_num>>15>>1>>15;
  return is_32;
}


int main() {
  int result = int_size_is_32();
  printf("int_size_is_32 %x\n", result);
  return 0;
}