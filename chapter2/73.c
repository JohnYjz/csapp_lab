#include<stdio.h>

int saturating_add(int x, int y) {
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
  int negative_overflow_result = 1<<shift_val;
  int positive_overflow_result = ~(negative_overflow_result);

  int result = sum;
  positive_overflow && (result = positive_overflow_result);
  negative_overflow && (result = negative_overflow_result);
  return result;
}


int main() {
	printf("%d\n", saturating_add(1, 2));
  printf("%d\n", saturating_add(2147483647, 2147483647));
  printf("%d\n", saturating_add(-2147483648, -2147483648));
  return 0;
}