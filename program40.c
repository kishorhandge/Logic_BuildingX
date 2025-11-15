// Input: 10
// 2   4   6   8   10
#include <stdio.h>

void Display(int iNo)
{

    int iCnt = 0;
    for (iCnt = 2; iCnt <= iNo; iCnt = iCnt + 2)
    {

        printf("%d\t", iCnt);
    }
}

int main()
{
    int iValue = 0;

    printf("Please Enter The Frequency : \n");
    scanf("%d", &iValue);

    Display(iValue);

    return 0;
}