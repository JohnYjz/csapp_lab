#include <stdio.h>

/* 
不允许溢出
假设为32位
太复杂了，而且结果好像挫了

进位应该是先乘再加
 */

int mul3div4(int x) {
  int mul_result = (x << 1) + x;

  int shift_val = (sizeof(mul_result) << 3) - 1;
  int isNeg = ((mul_result >> shift_val) & 1) == 1;
  isNeg && (mul_result = (mul_result + (1 << 2) - 1));
  return mul_result >> 2;
}

int threefourths(int x) {
  // 一 、 第一版答案
  // int low_half_int = x & 0x0000FFFF;
  // int high_haf_int = (x >> 16) & 0x0000FFFF;

  // int mul_low_result = (low_half_int << 1) + low_half_int;
  // int mul_low_carry = (mul_low_result >> 16) & 0x0000FFFF;
  // mul_low_result = mul_low_result & 0x0000FFFF;

  // int mul_high_result = (high_haf_int << 1) + high_haf_int + mul_low_carry;

  // int isNeg = ((mul_high_result >> 16) & 1) == 1;
  // isNeg && (low_half_int = (low_half_int + (1 << 2) - 1));

  // low_half_int = low_half_int >> 2;
  // int high_haf_int_last2 = (mul_high_result & 0x2) << 14;
  // low_half_int = low_half_int | high_haf_int_last2;
  // mul_high_result = (mul_high_result >> 2) << 16;
  // return mul_high_result | low_half_int;


  /*
    二、网上答案
    基本思路：3/4x=1/4x+1/2x。对于舍入误差来说，只与
    符号位和最低两位有关。据此编写程序
  */
  // int a = x>>((sizeof(int)<<3)-1); // 最高位
  // int b = x & 1; // 最低位
  // int c = (x & 3 - b)>>1; // 最低两位 - 最低一位 >> 1
  // int diff = b + c;
  // int mis = !a && !(b==0&&c==0);
  // return (x>>2)+(x>>1)+diff-mis;

  // 三、正确的自己的答案
  int high_accurate = ((x >> 2) + (x >> 1)) & (~0x3);
  int low_accurate = mul3div4(x) & 0x3;
  return high_accurate | low_accurate;
}
int main() {
  printf("%d\n", threefourths(-2147483647));
  // 直接计算的结果       1610612735
  // 我最初自己的答案      1610596352
  // 网上的答案           1610612735
  return 0;
}