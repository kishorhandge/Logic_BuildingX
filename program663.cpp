//input--> 4
//output--> 4*3*2*1 = 24

#include<iostream>
using namespace std;

int Factorial(int iNo)
{   
    static int iFact = 1;
    
    if(iNo >= 1)
    {
        iFact = iFact * iNo;
        Factorial(iNo--);   //post decrement-->Means first pass the value then decrement.
        
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