#include<stdio.h>
#include<stdlib.h>

float Average(int Arr[],int iSize)
{
    int iCnt = 0,iSum = 0;
    float fAvg= 0.0f;

    for(iCnt = 0;iCnt < iSize;iCnt++)
    {    
        iSum = iSum+Arr[iCnt];

        fAvg = iSum/iSize;   //Issue
    }

    return fAvg; 
}

int main()
{   
    int iLength = 0,iCnt = 0;
    float fRet=0.0f;
    int *ptr = NULL;

    printf("Enter Number Of Elements:\n");
    scanf("%d",&iLength);

    ptr = (int *)malloc(iLength*sizeof(int));
    
    if(NULL == ptr  ) // Industrial way of coding
    {
        printf("Unable to allocate memory");
        return -1;
    }

    printf("Enter the elements:\n");

    for(iCnt = 0;iCnt < iLength;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    fRet = Average(ptr,iLength);

    printf("Average of elements are :%f\n",fRet);

    free(ptr);

    return 0;
}