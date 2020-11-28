#include <stdio.h>

typedef unsigned float_bits;

/* 
思考一下
1、如果是 0.x 的形式
E = 1 - (2^3 - 1) = -6;
则阶码的值固定为 e = 1 ^ (-6)
最终值为 v = e * M
这种形式直接小数点左移

2、如果是 x.x 的形式
v = e * M
  = 2^(阶码值 - 7) * (1 + 尾数码的值)
  = (2^阶码的值) * (1 + 尾数码的值)/(2^7)

 */
float_bits float_twice(float_bits f) {
  float_bits exp = (f >> 23) & 0x000000ff;
  float_bits frac = f & 0x00007fffff;
  if (exp == 0x000000ff) {// 阶码全为1，为NaN，或者无穷
    return f;
  }
  if (exp == 0 && frac < 0x00007fffff) {
    return exp | (frac << 1) | (f & 0x80000000);
  }

  if (exp == 0 && frac == 0x00007fffff) {
    frac = 0x00007ffffe;
    return (exp + 1) | frac | (f & 0x80000000);
  }

  if (exp == 0xfe) { // +1 即为无穷
    return f;
  }
  
  return (exp + 1) | frac | (f & 0x80000000);
}

int main () {
  float a = 123.0;
  float b = -123.0;
  printf("orign 123 is: %x\n", (unsigned)a);
  printf("%x\n", float_twice(a));
  printf("orign -123 is: %x\n", (unsigned)b);
  printf("%x\n", float_twice(b));
}