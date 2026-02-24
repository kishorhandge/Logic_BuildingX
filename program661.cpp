//input--> 4
//output--> 4*3*2*1 = 24

#include<iostream>
using namespace std;

int Factorial(int iNo)
{   
    int iFact = 1;
    
    while(iNo >= 1)
    {
        iFact = iFact * iNo;
        iNo--;
        
    }
    return iFact;

}
int main()
{   
    int iRet = 0;

    iRet = Factorial(4);

    cout<<"Factorial is :"<<iRet<<"\n";

    return 0;
}