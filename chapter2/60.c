#include <stdio.h>

typedef unsigned char *byte_pointer;

unsigned replace_byte(unsigned x, int i , unsigned char b) {
  size_t len = sizeof(unsigned);
  byte_pointer x_as_bytes = (byte_pointer) &x;
  x_as_bytes[i] = b;
  return x;
}

int main () {
  unsigned test_num = 0x12345678;
  unsigned result1 = replace_byte(test_num, 2, 0xAB);
  printf("%x\n", result1);
  unsigned result2 = replace_byte(test_num, 0, 0xAB);
  printf("%x\n", result2);
  return 0;
}