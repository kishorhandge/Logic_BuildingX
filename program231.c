#include <stdio.h>

void CountAll(char str[])
{
    int iCountSmall = 0, iCountCapital = 0;

    while (*str != '\0')
    {
        if ((*str >= 'A' && *str <= 'Z'))
        {
            iCountSmall++;
        }
        else if ((*str >= 'a' && *str <= 'z'))
        {
            iCountCapital++;
        }

        str++;
    }
    printf("Number of small character are:%d\n", iCountSmall);
    printf("Number of capital character are:%d\n", iCountCapital);
}

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter String :\n");
    scanf("%[^'\n']s", Arr);

    CountAll(Arr);

    return 0;
}