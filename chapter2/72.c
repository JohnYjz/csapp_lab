#include<stdio.h>
#include<string.h>

void copy_int(int val, void *buf, int maxbytes) {
  // int - size_t
  // 即 int - unsigned 则int被强制转换为 unsigned 具体查看p53
  // 相减会等待一个无符号数，一定大于0
  // 修改为 maxbytes >= sizeof(val)
  if (maxbytes - sizeof(val) >= 0) {
    // void *destin, void *source, unsigned n
    memcpy(buf, (void *)&val, sizeof(val));
  }
}
