#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
  printf("%ld\n", (long)getpid());
  exit(0);
}