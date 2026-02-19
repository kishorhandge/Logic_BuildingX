//input--> 4
//output--> 4 3 2 1

#include<iostream>
using namespace std;

void Display(int iNo)
{   
   int iCnt = 0;

    iCnt = iNo;

    while(iCnt >= 1)
    {
        cout<<iCnt<<"\n";
        iCnt--;
        
    }
}
int main()
{
    Display(4);

    return 0;
}