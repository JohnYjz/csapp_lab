#include <stdio.h>

typedef unsigned float_bits;

/* 未声明网上答案和我的不一样？ 因为有扣一个偏置，这个好像不太对 */
float_bits float_twice(float_bits f) {
  float_bits exp = (f >> 23) & 0x000000ff;
  float_bits frac = f & 0x00007fffff;
  if (exp == 0x000000ff) {// 阶码全为1，尾数不为0，为NaN
    return f;
  }
  float_bits sign_f = (f >> 31) & 0x1;
  float_bits result = (f << 1) & 0x7FFFFFFF;
  result = result | (sign_f << 31);
  return result;
}

int main () {
  float a = 123.0;
  float b = -123.0;
  printf("orign 123 is: %x\n", (unsigned)a);
  printf("%x\n", float_twice(a));
  printf("orign -123 is: %x\n", (unsigned)b);
  printf("%x\n", float_twice(b));
}