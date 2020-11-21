// 55、57
#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) { // sizeof 返回的类型
  size_t i;
  for (i = 0; i < len; i++) {
    // x - unsigned int,十六进制
    // .2 输出数字的精度，这里是指整数2位
    printf("%.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x) {
  show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
  show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x) {
  show_bytes((byte_pointer) &x, sizeof(double));
}

/* 
结论，我的mac为64位机，结果：
int 4个字节
short 2个字节
long 8个字节
float 4个字节
double 8个字节
char* 8个字节

和书上64位机的数据类型定义一致
 */

int main() {
  int x = 12345; // ox00003039
  show_int(x); // 39 30 00 00 最低位先输出，小端机器
  float y = 12345.0;
  show_float(y); // 00 e4 40 46
  int* z = &x;
  show_pointer(z); // 08 47 c5 ec fe 7f 00 00
  short j = 12345;
  show_short(j); // 39 30
  long k = 12345;
  show_long(k); // 39 30 00 00 00 00 00 00
  double i = 12345.0;
  show_double(i); // 00 00 00 00 80 1c c8 40
  return 0;
}