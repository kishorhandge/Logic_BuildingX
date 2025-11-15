// Input : 12    2       True
// Input : 12    6       True
// Input : 12    5       False
// Input : 12    12      True
// Input : 12    7       False

#include <stdio.h>

int main()
{
    int iValue1 = 0, iValue2 = 0;

    printf("Enter First Number\n");
    scanf("%d", &iValue1);

    printf("Enter Second Number\n");
    scanf("%d", &iValue2);

    if ((iValue1 % iValue2) == 0)
    {
        printf("It Is Completely Divisible\n");
    }
    else
    {
        printf("It Is Not  Divisible\n");
    }

    return 0;
}