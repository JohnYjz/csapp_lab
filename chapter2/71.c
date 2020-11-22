#include<stdio.h>

typedef unsigned packed_t;
/* 没有考虑到高位为0 */
int xbyte(packed_t word, int bytenum) {
  int left_move = (3 - bytenum) << 3;
  int right_move = 3 << 3;
  return ((int) word) << left_move >> right_move;
}


int main() {
  packed_t word = 0x8008FF00;
	printf("%d\n", xbyte(word, 0));
	printf("%d\n", xbyte(word, 1));
	printf("%d\n", xbyte(word, 2));
	printf("%d\n", xbyte(word, 3));
  return 0;
}