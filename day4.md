1.打开一个流
    1) FILE *fopen(const char *path, const char *type);
    2) FILE *freopen(const char *path, const char *type, FILE *fp);
    3) FILE *fdopen(int fd, const char *type);
    失败返回 NULL

    type:
    1."r" 只读
    2."w" 只写，清空原内容  文件不存在时创建
    3."a" 只写，末尾追加    不存在时创建
    "+" 表示在不影响原模式基础上，增加另外一种能力
    4."r+" 读写，文件不存在报错，打开时不清空，初始位置在文件开头
    5."w+"
    6."a+"
    7."b" 二进制打开

2.关闭一个流
    int fclose(FILE *fp); 
    返回值:0 成功   EOF:失败

3.读取一个字节
    int getc(FILE *fp);
    返回读到的字节，未读到则返回 EOF(-1)

4.流出错排查
    1.int ferror(FILE *fp); 判断文件是否出错
    2.int feof(FILE *fp);   判断文件是否未读取到字节？
    3.void clearerr(FILE *fp); 清除标志位

5.把字节压回流
    1.int unget(inc c, FILE *fp)
    使用这个函数时，不会修改底层文件，而是修改流

6.向fp写入一个字节
    1.int putc(int c, FILE *fp);
    putc会把c转换为 unsigned char 然后写入这个字节，不会把整个int占的这几个字节写入

7.每次一行IO
    1.char *fgets(char *restrict buf, int n, FILE *fp);
    示例:
        char rd[6];
        char *result = fgets(rd, sizeof rd, fp);
        会读至多5个字节，最后一个位置给'\0',并且遇到'\n'时也会提前结束