/*
Algorithm:
START
    Accept the number and store as No
    Divide no by 2
    If the remainder is 0 
        then display as even
    Otherwise 
        display as odd

STOP
*/

#include<stdio.h>

void CheckEvenOdd(int iNo)
{
    int iRem=0;

    iRem=iNo%2;

    if(iRem == 0)
    {
        printf("It is Even number\n");
    }
    else
    {
        printf("It is Odd number\n");
    }
}

int main()
{   
    int iValue=0;

    printf("Enter the Number\n");
    scanf("%d",&iValue);

    CheckEvenOdd(iValue);

    return 0;
}