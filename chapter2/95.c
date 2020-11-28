#include <stdio.h>

typedef unsigned float_bits;

/* 
非规格化数
2^(-6) * f
即frac >> 1

规格化数
2^(阶码的值) * (1 + f) / (2^(-7))
则exp - 1
最小规格化数，exp -1，且frac >> 1


这里的舍入怎么做？需要舍入吗？？？
 */
float_bits float_half(float_bits f) {
  float_bits exp = (f >> 23) & 0x000000ff;
  float_bits frac = f & 0x00007fffff;
  if (exp == 0x000000ff) {// 阶码全为1，为NaN，或者无穷
    return f;
  }
  if (exp == 0) {
    return exp | (frac >> 1) | (f & 0x80000000);
  }

  if (frac == 0x01) {
    return (exp - 1) | (frac >> 1) | (f & 0x80000000);
  }
  
  return (exp - 1) | frac | (f & 0x80000000);
}

int main () {
  float a = 123.0;
  float b = -123.0;
  printf("orign 123 is: %x\n", (unsigned)a);
  printf("%x\n", float_half(a));
  printf("orign -123 is: %x\n", (unsigned)b);
  printf("%x\n", float_half(b));
}