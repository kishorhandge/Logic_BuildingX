#include<stdio.h>

void StrCatX(char *src ,char *dest)
{   
    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {   
        *dest = *src;

        src++;
        dest++;

    }
    *dest = '\0'; //---> *dest = *src
}
int main()
{
    char Arr[50] = {'\0'};
    char Brr[50] = {'\0'};

    printf("Enter the Source String:\n");
    scanf("%[^'\n']s",Arr);

    fflush(stdin);

    printf("Enter the Destination String:\n");
    scanf("%[^'\n']s",Brr);

    StrCatX(Arr,Brr);

    printf("Updated String is : %s\n",Brr);

    return 0;
}