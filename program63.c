#include <stdio.h>

int main()
{
    int iNo = 723614;
    int iDigit = 0;

    printf("_______________________________________________\n");

    printf("Orignal value of iNo is : %d\n ", iNo);

    printf("_______________________________________________\n");
    iDigit = iNo % 10;
    printf("iDigit is : %d\n", iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n", iNo);

    printf("_______________________________________________\n");

    iDigit = iNo % 10;
    printf("iDigit is : %d\n", iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n", iNo);

    printf("_______________________________________________\n");

    iDigit = iNo % 10;
    printf("iDigit is : %d\n", iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n", iNo);

    printf("_______________________________________________\n");

    iDigit = iNo % 10;
    printf("iDigit is : %d\n", iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n", iNo);

    printf("_______________________________________________\n");

    return 0;
}