#include <unistd.h>
#include <stdio.h>

int main(void){
    int a = truncate("test.txt", 2);
    return 0;
}