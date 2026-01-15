#include <stdio.h>
#include <stdlib.h>
// #include<unistd.h>
#include <fcntl.h>

int main()
{
    int fd = 0,iRet = 0;

    char Fname[100] = {'\0'};
    char Buffer[100] = {'\0'};

    printf("Enter the name of file:\n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDWR);
    
    if(fd != -1)
    {
        printf("File succesfully opened:\n");

        iRet = read(fd,Buffer,10);

        printf("data from file is:\n");

        write(1,Buffer,iRet);

        printf("\n");

        close(fd);
    }
    else
    {
        printf("There is no such file\n");
    } 

    return 0;
}
/*
    1 → stdout (screen)

    Buffer → data to be printed

    iRet → number of bytes to write
*/