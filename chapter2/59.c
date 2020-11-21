#include <stdio.h>

typedef unsigned char *byte_pointer;

byte_pointer create_byte_by_concat(byte_pointer x, byte_pointer y) {
  size_t len = sizeof(unsigned long);
  for (size_t i = 0; i < len; i++) {
    if (i != 0) {
      x[i] = y[i];
    }
  }
  return x;
}

void print_byptes(byte_pointer x, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%.2x", x[i]);
  }
  printf("\n");
}


int main() {
  int x = 123456;
  int y = 678910;
  printf("x:\n"); // 转的这个unsigned long是不是不优雅
  print_byptes((byte_pointer) &x, sizeof(int));
  printf("y:\n");
  print_byptes((byte_pointer) &y, sizeof(int));
  unsigned long bytex = (unsigned long)x;
  unsigned long bytey = (unsigned long)y;
  printf("bytex:\n");
  print_byptes((byte_pointer) &bytex, sizeof(unsigned long));
  printf("bytey:\n");
  print_byptes((byte_pointer) &bytey, sizeof(unsigned long));
  byte_pointer result = create_byte_by_concat((byte_pointer) &bytex, (byte_pointer) &bytey);
  printf("result:\n");
  print_byptes(result, sizeof(unsigned long));
}