#include<stdio.h>

void StrCpyX(char *src ,char *dest)
{
    while(*src != '\0')
    {
        *dest = *src;

        src++;
        dest++;

    }
    *dest = '\0';
}
int main()
{
    char Arr[50] = {'\0'};
    char Brr[50] = {'\0'};

    printf("Enter the String:\n");
    scanf("%[^'\n']s",Arr);

    StrCpyX(Arr,Brr);

    printf("Copied String is :%s\n",Brr);

    return 0;
}