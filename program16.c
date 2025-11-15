///////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required Header files:
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>                  //for input output
#include <stdbool.h>                //for bool datatype

///////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:  CheckEvenOdd
//  Description:    check weather number is even or odd
//  Input:          Interger        
//  Output:         boolean
//  Author:         kishor suryabhan handge
//  Dtae:           10/10/2025
///////////////////////////////////////////////////////////////////////////////////////////////


bool CheckEvenOdd(int iNo)
{
    int iRem = 0;

    iRem = iNo % 2;

    if (iRem == 0)
    {   return true;    }
    
    else{   return false;   }
       
}
///////////////////////////////////////////////////////////////////////////////////////////////
//
//   Entry point function of appliaction
//
///////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iValue = 0;
    bool bRet = false;

    printf("Enter the Number\n");
    scanf("%d", &iValue);

    bRet = CheckEvenOdd(iValue);
    
    if(bRet == true)
    {
        printf("%d is Even  number\n",iValue);
    }
    else
    {
        printf("%d is Odd  number\n",iValue);
    }
    
    return 0;
}

