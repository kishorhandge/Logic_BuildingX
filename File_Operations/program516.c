/*
--> read() system call does not add a '\0' (null character) at the end of data.
--> printf("%s") prints characters until it finds '\0'.
--> So even after closing the file descriptor, old memory data may get printed.
--> Therefore, we must manually add '\0' after read() to print correct output.

*/

#include <stdio.h>
#include <stdlib.h>
// #include<unistd.h>
#include <fcntl.h>

int main()
{
    int fd = 0;
    int iRet = 0;

    char Buffer[100] = {'\0'};

    char Arr[10] = {'\0'};

    fd = open("JanuaryX.txt", O_RDONLY);

    printf("file gets opened with fd :%d\n", fd);

    iRet = read(fd, Buffer, 11);
    printf("data from file is : %s\n", Buffer);
    printf("Return value of read is : %d\n", iRet);

    close(fd);

    fd = open("JanuaryX.txt", O_RDONLY);

    iRet = read(fd, Arr, 10);
    printf("data from file is : %s\n", Arr);
    printf("Return value of read is : %d\n", iRet);

    close(fd);

    return 0;
}