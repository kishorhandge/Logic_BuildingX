#include <stdio.h>

void StrtoggleX(char str[])
{
    while (*str != '\0')
    {
        if ((*str >='A' && *str <='Z'))
        {
            *str = *str + 32;
        }
        else if((*str >='a' && *str <='z'))
        {
            *str = *str - 32;
        }
        
        str++;
    }
     
}
//Time Complexity : O(N), where N is number of letter

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter String :\n");
    scanf("%[^'\n']s", Arr);

    StrtoggleX(Arr);

    printf("Updated String is :%s\n",Arr);
    return 0;
}