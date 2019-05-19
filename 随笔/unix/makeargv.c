#include <errno.h>
#include <stdlib.h>
#include <string.h>

int makeargv(const char *s, const char *delimiters, char ***argvp) {
    int error;
    int i;
    int numtokens;
    const char *snew;
    char *t;
    if ((s == NULL) || (delimiters == NULL) || (argvp == NULL)) {
        errno = EINVAL;
        return -1;
    }
    *argvp = NULL;
    snew = s + strspn(s, delimiters);
    if ((t = malloc(strlen(snew) + 1)) == NULL) 
        return -1;
    strcpy(t, snew);
    numtokens = 0;
    /*
    定义函数：char * strtok(char *s, const char *delim);
    函数说明：strtok()用来将字符串分割成一个个片段。
    参数s 指向欲分割的字符串，参数delim 则为分割字符串，当strtok()在参数s 的字符串中发现到参数delim 的分割字符时则会将该字符改为\0 字符。
    在第一次调用时，strtok()必需给予参数s 字符串，往后的调用则将参数s 设置成NULL。
    每次调用成功则返回下一个分割后的字符串指针。
    返回值：返回下一个分割后的字符串指针，如果已无从分割则返回NULL。
    */
    // 找到命令有几个分段
    if (strtok(t, delimiters) != NULL)
        for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++);
    // 给 *argvp 分配 numtokens+1 个指针
    if ((*argvp = malloc((numtokens+1)*(char *))) == NULL) {
        error = errno;
        free(t);
        errno = error;
        return -1;
    }
    if (numtokens == 0)
        free(t);
    else {
        strcpy(t, snew);
        **argvp = strtok(t, delimiters);
        for (i = 1; i < numtokens; i++)
            *((*argvp) + i) = strtok(NULL, delimiters);
    }
    *((*argvp) + numtokens) = NULL;
    return numtokens;
}