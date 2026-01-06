#include<iostream>
using namespace std;

template<class T>
T Addition(T No1,T No2)
{
    T Ans = 0;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    float i = 0.0f,j = 0.0f;
    float Ret = 0.0f;

    cout<<"Enter the First Number: \n";
    cin>>i;

    cout<<"Enter the Second Number: \n";
    cin>>j;

    Ret = Addition(i,j);

    cout<<"Addition is :"<<Ret<<"\n";

    return 0;
}