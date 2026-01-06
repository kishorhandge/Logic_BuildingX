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
    cout<<"Addition of Characters :"<<Addition('a','b')<<"\n";
    cout<<"Addition of Integers :"<<Addition(11,10)<<"\n";
    cout<<"Addition of floats :"<<Addition(90.4f,45.5f)<<"\n";
    cout<<"Addition of doubles :"<<Addition(34.43222,56.5443)<<"\n";

    return 0;
}