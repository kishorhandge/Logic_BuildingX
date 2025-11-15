#include <stdio.h>

void CountFactorsNonFactors(int iNo)
{
    int iCnt = 0, iFrequency1 = 0, iFrequency2 = 0;

    if (iNo < 0)
    {
        iNo = -iNo;
    }

    for (iCnt = 1; iCnt < iNo; iCnt++)
    {
        if ((iNo % iCnt) == 0)
        {
            iFrequency1++;
        }
        else
        {
            iFrequency2++;
        }
    }

    printf("Number Of Factors Are : %d", iFrequency1,"\n");
    printf("Number Of Non Factors Are : %d", iFrequency2,"\n");
}

int main()
{
    int iValue = 0;

    printf("Enter The Number :\n");
    scanf("%d", &iValue);

    CountFactorsNonFactors(iValue);

    return 0;
}