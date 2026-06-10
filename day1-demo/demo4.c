#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
  errno = EINVAL;
  strerror(errno);
  perror("test");
  exit(0);
}