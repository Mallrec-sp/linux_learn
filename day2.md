1.文件操作
    1.总览
        open, read, write, lseek, close
    2.文件描述符是一个非负整数
    3.open openat函数
        头文件：#include <fcntl.h>
        int open(const char *path, int flag);
        int openat(int fd, const char *path, int flag);
        #flag
            1.O_RDONLY      只读        0
            2.O_WRONLY      只写        1
            3.O_RDWR        读写        2
            4.O_EXEC        只执行打开
            5.O_SEARCH      只搜索打开，用于目录搜索
            6.O_APPEND      追加
            7.O_CREAT       文件不在则创建
        #返回的fd是最小的未用文件描述符数值

    4.creat函数
        #头文件: #include <fcntl.h>
        int creat(const char *path, mode_t mode);
        等价于 open(const char *path, O_RDWR | O_CREAT | O_TRUNC, mode);

    5.close 
        #头文件 #include <unistd.h>
        int close(int fd);

    6.lseek
        #打开文件的时候，除非指定了O_APPEND, 否则偏移量都是0
        #lseek 可以显式的给一个打开的文件设置偏移值
        #头文件 #include <unistd.h>
        off_t lseek(int fd, off_t offset, int whence)
        #参数whence
            1.SEEK_SET                  偏移量设置为距文件开始处offset字节
            2.SEEK_CUR                  设置为当前值+offset,offset可正可负
            3.SEEK_END                  设置为文件长度+offset.可正可负
        #成功执行则返回新的偏移量，否则返回-1,fd指向管道FIFO，socket时返回-1

    7.read  
        #头文件     #include <unistd.h>
        ssize_t read(int fd, void *buf, size_t nbytes);
        返回读取到的字节数，已经到文件尾部返回0,出错为-1
    8.write
        #头文件     #include <unistd.h>
        ssize_t write(int fd, const void *buf, size_t nbytes);

    9.pread
        ssize_t pread(int fd, void *buf, size_t nbytes, off_t offset);
            。不会更新当前文件的偏移了
        
    10.pwrite

2.dup和dup2函数
    #可以用来复制一个现有的文件描述符，类比引用
    #头文件: #include <unistd.h>
    # int dup(int fd);
      int dup2(int fd, int fd2); 
    #返回值一定是当前可用文件描述符中的最小数值

3.sync, fsync, fdatasync
    #作用:把延迟i写数据块写入磁盘
    #头文件: #include<unistd.h>
    1.int fsync(int fd);
        #只对目标fd指定的文件起作用，等待写磁盘操作结束才返回
    2.int fdatasync(int fd);
        #只影响文件的数据部分
    3.void sync(void);
        #只是将所有修改过的块缓冲区写队列，不等待磁盘操作结束

4.fcntl
    #作用:可以改变已经打开文件的属性
    #头文件:#include <fcntl.h>
    int fcntl(int fd, int cmd);
    