#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
    int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
    char *buf;
    ssize_t num = read(fd, buf, 3);
    printf("%s", buf);
    return 0;
}
