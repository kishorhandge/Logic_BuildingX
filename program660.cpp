//input--> 4
//output--> 4+3+2+1 = 10

#include<iostream>
using namespace std;

int Addition(int iNo)
{   
    static int iSum = 0;
    
    if(iNo >= 1)
    {
        iSum = iSum + iNo;  
        iNo--;
        Addition(iNo);
        
    }
    return iSum;

}
int main()
{   
    int iRet = 0;

    iRet = Addition(4);

    cout<<"Addition is :"<<iRet<<"\n";

    return 0;
}