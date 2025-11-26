#include<stdio.h>
#include<fcntl.h>

int main()
{   
    int fd = 0;

    char FileName[20];

    printf("Enter the name of file that you want to close :\n");
    scanf("%s",FileName);

    fd = open(FileName,O_RDWR);

    if(fd == -1)
    {
        printf("unable to open  the file:\n");
    }
    else
    {
        printf("File successfully cretaed with fd : %d\n",fd);
    }

    close(fd);

    return 0;
}