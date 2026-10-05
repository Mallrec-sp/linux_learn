#include <stdio.h>

int main(){
    FILE *fp = fopen("./test.txt", "a+");
    char rd[6];
    char *read_result = fgets(rd, 6, fp);
    printf("%s", read_result);
    fclose(fp);
}