#include<stdio.h>
#include<stdbool.h>

bool CheckPrime(int iNo)
{
    int iCnt=0;
    bool bFlag=true;

    if(iNo<0)
    {
        iNo=-iNo;
    }
    
    for(iCnt=2;iCnt<=(iNo/2);iCnt++)
    {
        if((iNo%iCnt) == 0)
        {
            bFlag=false;
            break;          //Optimization Due To Break
        }
    }

    return bFlag;

}

int main()
{   
    int iValue=0;

    bool bRet=false;

    printf("Enter The Number :\n");
    scanf("%d",&iValue);

    bRet=CheckPrime(iValue);

    if(bRet ==true)
    {
        printf("%d is a prime number\n",iValue);
    }
    else
    {
        printf("%d is not a prime number\n",iValue);
    }

    return 0;
}
//Time Complexity For Prime : O(N/2)

//Time Complexity For Non Prime :Either 1 Or 2

