#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int r_close(int r_fildes)
{
    int error;
    while ((error = close(r_fildes) == -1) && (errno == EINTR));
    return error;   
}