#include <iostream>
using namespace std;

void Display()
{   
    auto  iCnt = 0;       //Auto Storage class

    cout << "Jay Ganesh..."<<iCnt<<"\n";
    iCnt++;

    Display();
}

int main()
{
    Display();

    return 0;
}