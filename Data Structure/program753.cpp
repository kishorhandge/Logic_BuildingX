#include <iostream>
using namespace std;

class ArrayX
{
    public:
    int *Arr;
    int iSize;

    ArrayX(int no);
    ~ArrayX();
    void Accept();
    void Display();
    bool LinearSearch(int iNo);
    bool BidirectionalSearch(int iNo);
    bool CheckSorted();

};


ArrayX :: ArrayX(int no)
{
    cout << "Inside Constructor" << "\n";
    iSize = no;
    Arr = new int[iSize];
}

ArrayX :: ~ArrayX()
{
    cout << "Inside Destructor:" << "\n";
    delete[] Arr;
}
void ArrayX :: Accept()
{
    int iCnt = 0;

    cout << "Enter the elements:" << "\n";

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];
    }
}
void ArrayX :: Display()
{
    int iCnt = 0;

    cout << "Elements of Array are:" << "\n";

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << Arr[iCnt] << "\t";
    }
    cout << "\n";
}

bool ArrayX :: LinearSearch(int iNo)
{
    int iCnt = 0;

    bool bFlag = false;

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        if (Arr[iCnt] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

bool ArrayX :: BidirectionalSearch(int iNo)
{
    int iStart = 0;
    int iEnd = 0;

    bool bFlag = false;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == iNo || Arr[iEnd] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}


bool ArrayX :: CheckSorted()
{
    int i = 0;

    bool bFlag = true;

    for(i = 0;i < iSize - 1;i++)
    {
        if(Arr[i] > Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

int main()
{

    int iValue = 0;
    bool bRet = false;

    cout << "Enter the number of elements:\n";
    cin >> iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    aobj.Display();

    /*if (aobj.LinearSearch(21))
    {
        cout << "Element is present \n";
    }
    else
    {
        cout << "There is no such Element \n";
    }

    if (aobj.BidirectionalSearch(21))
    {
        cout << "Element is present \n";
    }
    else
    {
        cout << "There is no such Element \n";
    }*/

    if(aobj.CheckSorted() == true)
    {
        cout<<"Data is sorted \n";
    }
    else
    {
        cout<<"Data is not sorted \n";
    }

    return 0;
}