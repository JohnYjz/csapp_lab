#include<stdio.h>

int odd_ones(unsigned x) {
  /* 包含奇数个1 return 1，假定32位，只能包含12个算数、位、逻辑运算 */
  /* 
  思路：
  异或后，消掉两个同为1和同为0的，只保留在该为上只出现一个1
  因此将32位的每每对半异或，消掉的1位偶数个，可以不计入统计
  最终异或到最后1位的时候，其结果就是
   */
  x = (x >> 16) ^ x; // 高16位挪到低16位作对比，只取低16位
  x = (x >> 8) ^ x;
  x = (x >> 4) ^ x;
  x = (x >> 2) ^ x;
  x = ((x >> 1) ^ x) & 1;
  return x;
}


int main() {
  unsigned test_num = 0xffffffff;
  int odd_is_one = odd_ones(test_num);
  printf("odd_ones %d\n", odd_is_one);
  return 0;
}