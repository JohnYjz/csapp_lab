#include<stdio.h>

int tsub_ok(int x, int y) {
  y = -y;
  int shift_val = (sizeof(int) << 3) - 1;
  int sum = x + y;
  int sign_bit_x = (x >> shift_val) & 1;
  int sign_bit_y = (y >> shift_val) & 1;
  int sign_bit_sum = (sum >> shift_val) & 1;
  /*
  x_sign > 0 y_sign > 0, sum_sign < 0，则正溢出
  x_sign < 0 y_sign < 0, sum_sign > 0，则负溢出
  */
  
  int positive_overflow = (sign_bit_x && sign_bit_y) && !sign_bit_sum;
  int negative_overflow = (!sign_bit_x && !sign_bit_y) && sign_bit_sum;
  return positive_overflow || negative_overflow || 0;
}


int main() {
	printf("%d\n", tsub_ok(1, 2));
  printf("%d\n", tsub_ok(2147483647, -2147483647));
  printf("%d\n", tsub_ok(-2147483648, 2147483647));
  return 0;
}