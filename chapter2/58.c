// 58
#include <stdio.h>
/* 
思路：
输入一个 int 00 00 00 01
小端法循环拿到的第一个字节是 01
 */

int is_little_endian () {
  int testNumber = 1;
  unsigned char *testNumberAsStr = (unsigned char *)&testNumber;
  if (testNumberAsStr[0] == 1) return 1;
  return 0;
}

int main() {
  if (is_little_endian()) {
    printf("本机为小端机器\n");
  } else {
    printf("本机为大端机器\n");
  }
  return 0;
}