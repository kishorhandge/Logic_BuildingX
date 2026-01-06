#include<iostream>
using namespace std;

double Addition(double No1,double No2)
{
    double Ans = 0;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    double i = 0.0,j = 0.0;
    double Ret = 0.0;

    cout<<"Enter the First Number: \n";
    cin>>i;

    cout<<"Enter the Second Number: \n";
    cin>>j;

    Ret = Addition(i,j);

    cout<<"Addition is :"<<Ret<<"\n";

    return 0;
}