#include<stdio.h>

/* 
设置第32位的权重 weight =  2 ^ 32;
unsigned_x * unsigned_y = (int_x + int_x_31 * weight) * (int_y + int_y_31 * weight);
= (int_x * int_y) + (int_x * int_y_31 * weight) + (int_y * int_x_31 * weight) + (int_x_31 * int_y_31 * weight * weight)

其中 weight * weight = 2 ^ 64;
回想一下二进制转十进制，val * 2 ^ n， 相当于把 (int_x_31 * int_y_31) 放在了第64位上（起始位0）
由于，不舍去位的话，int * int 一共有效为是0-63，因此 (int_x_31 * int_y_31 * weight * weight) 被舍弃

即
= (int_x * int_y) + (int_x * int_y_31  + int_y * int_x_31) * weight

可以看出 (int_x * int_y_31  + int_y * int_x_31) * weight 表示 (int_x * int_y_31  + int_y * int_x_31) 的值乘了一个第32位的权重，即对低32位不影响，它是对高32位做的修正

那么相当于
signed_high_prod + (int_x * int_y_31  + int_y * int_x_31) 即为修正值
 */
unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int shift_val = (sizeof(unsigned) << 3) - 1;
  unsigned raw = signed_high_prod(x, y);
  int int_x_31 = ((x >> shift_val) & 1);
  int int_y_31 = ((y >> shift_val) & 1);
  return raw + x * int_y_31 + y * int_x_31;
}

