#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
#include<fcntl.h>

int main()
{   
    int fd = 0;
    int iRet = 0;

    char Buffer[100] = {'\0'};

    fd = open("JanuaryX.txt",O_RDONLY);

    if(fd != -1)
    {
        printf("file gets opened with fd :%d\n",iRet);

        iRet = read(fd,Buffer,11);

        printf("data from file is: %s\n",Buffer);

        close(fd);

    }

     
    return 0;
}