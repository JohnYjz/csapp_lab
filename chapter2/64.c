#include<stdio.h>

int any_odd_one(unsigned x) {
  // 掩码32位
  unsigned max_code = 0x55555555;
  return !!(x & max_code);
}


int main() {
  unsigned test_num = 0xaaaaaaaa;
  int odd_is_one = any_odd_one(test_num);
  printf("odd_is_one %d\n", odd_is_one);
  return 0;
}