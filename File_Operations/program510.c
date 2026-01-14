#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
#include<fcntl.h>

int main()
{   
    int fd = 0;
    int iRet = 0;
    
    char Arr[] = "Jay Ganesh";

    fd = open("JanuaryX.txt",O_RDWR | O_CREAT,0777);

    if(fd == -1)
    {
        printf("Unable to open a file:\n");
    }
    else
    {
        printf("file gets succesfully open with fd :%d\n",fd);
        iRet = write(fd,Arr,3);//kashat ky kiti

        printf("%d bytes gets succesfully written into the file\n",iRet);

        close(fd);
    }

     
    return 0;
}