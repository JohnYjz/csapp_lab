#include<stdio.h>

int isLessOrEqual(int x, int y) {
  /*
  x - y <= 0
  z = x + -y
  如果 sign_z == 1 return 1
  */
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int same_sign = !(sign_x ^ sign_y);
  int negative_y = (~y) + 1;
  int sub_result = x + negative_y;
  return ((!same_sign) & sign_x) | (same_sign & (!!(!sub_result | (sub_result >> 31))));
}

int main() {
	printf("result %x\n", isLessOrEqual(0x7fffffff, 0x80000000));
  return 0;
}