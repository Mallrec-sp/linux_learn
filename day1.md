1. /和空字符不能出现在文件名中
2. 可以使用cc demo.c编译，在GUN C编译系统中，是gcc， cc通常链接到gcc
3. 头文件 apue.h 包含了一些系统标准头文件，定义了很多常量 函数
4. dirent.h 可以使用 opendir等函数
    #include <dirent.h>
    #include <stdio.h>
    int main(){
      DIR *dir = opendir(".");
      if(dir == NULL){
        perror("opendir");
        return 1;
      }
      struct dirent *entry;
      while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
      }
      closedir(dir);
      return 0;
    }

5. 当运行一个新程序时，shell都将打开3个文件描述符， 标准输入，标准输出，标准错误，不加处理的话，都将链接向终端

6. 使用 ls ./test.txt > demo.md 使得标准输出重定向到某个文件
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

./a.out < test.txt > demo.txt 可以复制文件
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
定义在unistd.h中

并且read函数返回值是读取到的字节数，读取错误返回-1, 读到结尾为0

7. 程序是存储在磁盘上的可执行文件，内核会使用exec函数读入内存并执行
   程序的执行实例称为进程，具有唯一的一个数字标识符，称为PID，总是一个非负整数 
    使用getpid()可以获取PID
    
8. 一个进程内部所有线程共享同一地址空间，文件描述符，栈和进程的一些属性，能访问同一存储区域。
    线程也有id，但是只有在他所属进程才起作用
    
9. UNIX系统函数出错时，会返回一个负值，errno被设定为特定信息的值；
    <errno.h> 定义了errno, errno不会被设置为0
    C标准有两个函数，用于打印这个错误信息
    #include <string.h>
    char *strerror(int errnum);映射为一个出错消息字符串
    
    #include <stdio.h>
    void perror(const char *msg);基于当前的errno值，在标准错误上产生一条出错消息， 输出：msg: strerror(errno)\n
    
10. 用户标识：
    用户id
   0：root   getuid()可以获取用户id
   
   组id
       组被用于将若干用户集中到项目或部门里 getgid() 可以获取组id
       
11. 信号
    1.信号用于通知进程发生了某种情况

12. 时间
    日历时间UTC
    进程时间：成为CPU时间，度量进程使用的cpu资源
        用户CPU时间，执行用户指令需要的时间量
        系统CPU时间：为该进程执行内核程序经历的时间
