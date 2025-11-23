#include<stdio.h>
 
void Swap(int *p , int *q)
{
    int Temp = 0;

    Temp = *p;
    *p = *q;
    *q = Temp;
}

int main()
{
    int iValue1 = 11;
    int iValue2 = 21;

    printf("Before Swap : %d %d\n",iValue1,iValue2);

    Swap(&iValue1,&iValue2);

    printf("After Swap : %d %d\n",iValue1,iValue2);

    return 0;
}