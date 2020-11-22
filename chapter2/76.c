#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* p69 */
void* calloc(size_t nmemb, size_t size) {
  void *result = NULL;
  unsigned total = nmemb * size;
  printf("is overflow: %d\n", ((total/nmemb) != size));
  ((nmemb == 0) || (size == 0) || ((total/nmemb) != size)) && (result = NULL);
  !((nmemb == 0) || (size == 0) || ((total/nmemb) != size)) && (result = malloc((size * nmemb)));
  return result;
}

int main() {
  printf("%p\n", calloc(2147483647, 2147483647));
  printf("%p\n", calloc(1, 2));
  return 0;
}