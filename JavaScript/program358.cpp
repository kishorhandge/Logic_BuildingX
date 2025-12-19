#include<iostream>
using namespace std;

inline int Addition(int A, int B)   // inline: tells compiler to place function code where it is called to make execution faster
{
    return A+B;
}

int main()
{
    register int Ret = 0;       //suggests compiler to store variable in CPU register for faster access

    Ret = Addition(10,11);  // 10 + 11;

    cout<<"Addition is : "<<Ret<<"\n";

    return 0;
}