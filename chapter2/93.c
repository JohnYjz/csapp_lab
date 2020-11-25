#include <stdio.h>

typedef unsigned float_bits;

/* 浮点型转整数，是不是动了位的？ */
/* NaN需要直接返回 */
float_bits float_absval(float_bits f) {
  unsigned exp = (f >> 23) & 0x000000ff;
  unsigned frac = f & 0x00007fffff;
  if ((exp == 0x000000ff) && frac != 0) {// 阶码全为1，尾数不为0，为NaN
    return f;
  }
  printf("not NaN\n");
  return f & 0x7FFFFFFF;
}

int main () {
  float a = 123.0;
  float b = -123.0;
  printf("orign 123 is: %x\n", (unsigned)a);
  printf("%x\n", float_absval(a));
  printf("orign -123 is: %x\n", (unsigned)b);
  printf("%x\n", float_absval(b));
}