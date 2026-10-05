1.测试当前进程是否有权限操作文件 access
    #头文件:#include <unistd.h>
    #int access(const char *pathName, int mode);
     int faccessat(int fd, const char *pathName, int mode, int flag);
        返回值:成功返回0,失败返回-1
    #mode:
        F_OK    文件是否存在
        R_OK    文件是否可读
        W_OK
        X_OK

2.按位清除权限,只作用于创建文件的时候 umask
    #头文件 #include <sys/stat.h>
    # mode_t umask(mode_t mask);
    # 返回值是调用之前的旧掩码，linux中这个调用总是成功的
    # 例子：
        umask(0022);
        open("test.txt", O_WRONLY | O_CREAT | O_EXCL, 0666);
        得到的权限:0644
    #umask 会一直保留到下一次修改或者进程结束
    #影响的是新创建的文件，已经创建的不会受到影响
    #多线程共享掩码

3.改变现有的文件的访问权限
    #头文件 #include <sys/stat.h>
        1.int chmod(const char *pathName, mode_t mode);
        2.int fchmod(int fd, mode_t mode);
        3.int fchmodat(int fd, const char *pathName, mode_t mode, int flag);

4.更改文件的用户ID和组ID
    #头文件 #include <unistd.h>
    # int chown(const char *pathName, uid_t uid, gid_t gid);

5.du -s fileName    
    如果设置了 POSIXLY_CORRECT 报告的是1024字节块的数量
    否则为512

6.文件截断
    #头文件:#include <unistd.h>
     1.int truncate(const char *pathName, off_t length);
     2.int ftruncate(int fd, off_t length);
    #可扩张，新增的区域用\0填充

7.链接 link
    #头文件 #include <unistd.h>
        int link(const char *oldPath, const char *newPath);

    #软连接
        int symlink(const char *actual, const char *sym);

8.重命名 rename
    #头文件 #include <stdio.h>
     1.int rename(const char *old, const char *new);

9.文件夹操作
    #include <sys/stat.h>
     1.int mkdir(const char *pathName, mode_t mode);
     2.int mkdirat(int fd, const char *pathName, mode_t mode);

    #include <unistd.h>
     int rmdir(const char *name);

    #读目录
        #incldue <dirent.h>
            1.DIR *opendir(const char *pathName);
            2.DIR *fdopendir(inf fd);
            3.struct dirent *readdir(DIR *dp);
            4.int close(DIR *dp);

10.更改当前工作目录
    #include <unistd.h>
        1.chdir(const char *pathName);
        2.int fchdir(int fd);


标准IO库
