#include<stdio.h>

int leftmost_one(unsigned x) {
  /* 产生一个掩码，使得产生的结果只包含最高位的1 */
  /* 
  将最高位的1或到之后的每一位上
  右移1位|原 -> 将最高的1或到下一位上
  右移2位|上次结果 -> 将最高的2位或次高2位
  ...
  右移16位 | 上次结果 -> 将前半段的1都或到后半段
  上次结果>>1 则 000(最高位1变为0)11111111...11
  */
  x = x | (x>>1);
  x = x | (x>>2);
  x = x | (x>>4);
  x = x | (x>>8);
  x = x | (x>>16);
  unsigned mask_code = ~(x>>1);
  return x & mask_code;
}


int main() {
  unsigned test_num = 0x6600000;
  int odd_is_one = leftmost_one(test_num);
  printf("leftmost_one %x\n", odd_is_one);
  return 0;
}