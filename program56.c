#include<stdio.h>
#include<stdbool.h>

bool CheckPrime(int iNo)
{
    int iCnt=0;

    if(iNo<0)
    {
        iNo=-iNo;
    }

    for(iCnt=2;iCnt<=(iNo/2);iCnt++)
    {
        if((iNo%iCnt) == 0)
        {
            
            break;          //Optimization Due To Break
        }
    }
//-----
    if(iCnt>(iNo/2))        //No Factors
    {
        return true;
    }
    else                    //At least one factors
    {
        return false;
    }

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