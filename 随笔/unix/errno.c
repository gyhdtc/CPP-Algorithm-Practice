#include <unistd.h>
#include <stdio.h>

/* 对应于全局的错误信息变量 */
int errno;
int fildes;
/*
EBADF  fildes 无效
EINTR  close  信号中断
*/
int close(int fildes);

char *strerror(int errnum)
{

}
void perror(const char *s)
{
    int error;
    if (s != NULL)
    {
        error = errno;
        fprintf(stderr, "%s descriptor %d: %s\n",s, fildes, strerror(errno));
        // 输出对应于 errno 的错误信息
        errno = error;
    }
}
int main()
{
    //while((errno = close(fildes) == -1) && (errno == EINTR)); 
    if (close(fildes) == -1)
        perror("Failed to close the file");
}