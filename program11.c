
/*
Algorithm:
START
    Accept the first number as no1
    Accept the second number as no2
    If the input  is negative then convert it into positive
    Perform the addition of no1 and no2
    Display the additon on Screen

STOP
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required Header Files;
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:  AdditionTwoNumbers  
//  Description:    It is use to perform addition
//  Input:          Float,Float
//  Output:         Float
//  Author:         Kishor Suryabhan Handge
//  Date:           09/10/2025
/////////////////////////////////////////////////////////////////////////////////////////////////

float AdditionTwoNumbers(
                            float fNo1,                 //First Input
                            float fNo2                  //Second Input
                        )
{
    float fSum = 0.0f;                                  //To Store the Result

     
    if(fNo1<0.0f)                                       //Updater                               
    {
        fNo1=-fNo1;
    }

    if(fNo2<0.0f)                                       //Updater
    {
        fNo2=-fNo2;
    }

    fSum = fNo1 + fNo2;                                 //Business Logic
    return fSum;
}   //End of AdditionTwoNumbers

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry point Function for the appliacation
//
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    float fValue1 = 0.0f, fValue2= 0.0f;                //To Accept User Input  
    float fRet = 0.0f;                                  //To store the result

    printf("Enter the First Number:\n");
    scanf("%f", &fValue1);

    printf("Enter the Second Number :\n");
    scanf("%f", &fValue2);

    fRet=AdditionTwoNumbers(fValue1,fValue2);           //Method Call

    printf("Addition is: %f\n", fRet);

    return 0;
}   //End of main

/////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Test case succesfully handled by the application
//
//  Input1:10.3     Input2:3.2      Output:13.5
//  Input1:-10.3    Input2:3.2      Output:13.5
//  Input1:10.3     Input2:-3.2     Output:13.5
//  Input1:-10.3    Input2:-3.2     Output:13.5
//  Input1:10.5     Input2:0.0      Output:13.5
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////