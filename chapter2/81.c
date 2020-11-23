// 没有对w做变量支持，目前只试了32位，扩展一下也同理，有思路不做了
/*
a (1^w-k)(0^k)
b (0^w-k-j)(1^k)(0^j)
*/
#include <stdio.h>

int create_a_result(int w, int k) {
  /* 
  w = 4, k = 1
  1000
  1110
  需要移动4-1-1两位
  */
  int result = 0x1 << (w-1) >> (w-k-1);
  return result;
}

int create_b_result(int w, int k, int j) {
  int result = 0x1 << (w-1) >> k;
  int mask_code = ~(1 << (w-1));
  result = result & mask_code;
  result = result >> (w-k-j-1);
  return result;
}

int main() {
  printf("%x\n", create_a_result(32, 1)); // fffffffe 对的
  printf("%x\n", create_a_result(32, 0)); // fffffffe 对的
  printf("%x\n", create_b_result(32, 4, 1)); // 78 即 .。0000 0000 0000 0111 1000
  printf("%x\n", create_b_result(32, 0, 1));
  return 0;
}