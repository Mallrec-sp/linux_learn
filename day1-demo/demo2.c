#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFSIZE 4096
int main(void){
  int n;
  char buf[BUFFSIZE];
  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
    if(write(STDOUT_FILENO, buf, n) != n){
      perror("write_error");
    }
  }
  
  if(n < 0)
    perror("read_error");
  exit(0);
}