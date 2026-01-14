/*
-->write() system call prints exactly the number of bytes given to it.
-->It does NOT depend on '\0' (null character) like printf("%s").
-->So only the data read by read() gets printed once, even after closing the fd.
-->That is why write() is safer for file I/O compared to printf("%s").

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
    printf("data from file is :\n");

    write(1,Buffer,iRet);

    printf("\nReturn value of read is : %d\n", iRet);

    close(fd);

    fd = open("JanuaryX.txt", O_RDONLY);

    iRet = read(fd, Arr, 10);
    printf("data from file is : \n");

    write(1,Arr,iRet);

    printf("\nReturn value of read is : %d\n", iRet);

    close(fd);

    return 0;
}