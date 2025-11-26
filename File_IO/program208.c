#include<stdio.h>
#include<fcntl.h>

int main()
{   
    int fd = 0,iRet = 0;
    char FileName[20];

    char Data[50] = {'\0'};

    printf("Enter the name of file : \n");
    scanf("%s",FileName);

    fd = open(FileName,O_RDWR);

    if(fd == -1)
    {
        printf("Unable to oepn:\n");
        return -1;
    }

    iRet = read(fd,Data,7);

    printf("%d Bytes gets succesfully read :\n");

    printf("Data from file :");

    write(1,Data,iRet);

    printf("\n");

    close(fd);

    return 0;
}