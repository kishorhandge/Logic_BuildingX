//BUBBLE SORT

#include <iostream>
using namespace std;

class ArrayX
{
    public:
    int *Arr;
    int iSize;
    bool Sorted;

    ArrayX(int no);
    ~ArrayX();

    void Accept();
    void Display();

    bool CheckSorted();

    void BubbleSort();
    void InsertionSort();

};


ArrayX :: ArrayX(int no)
{
    cout << "Inside Constructor" << "\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
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
    cin >> Arr[iCnt];

    for (iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];

        if(Arr[iCnt - 1] > Arr[iCnt])
        {
            Sorted = false;
        }
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


//21 15 18 16 11
void ArrayX :: InsertionSort()
{   
    int i = 0, j = 0 ,key = 0;

    for(i = 1;i<iSize;i++)
    {
        key = Arr[i];
        j = i-1;

        while(j >= 0 && Arr[j] > key)
        {
            Arr[j+1] = Arr[j];
            j = j-1;
        }
        Arr[j+1] = key;

        cout<<"\nData after pass : "<<i+1<<"\n";
        Display();

    }
     
}

/*
    Time Complexity of Insertion Sort

    Worst Case Time Complexity  : O(n^2)
    (When array is in reverse order)

    Best Case Time Complexity   : O(n)
    (When array is already sorted)

    Average Case Time Complexity: O(n^2)

    Space Complexity            : O(1)
    (No extra space used, in-place sorting)
*/

int main()
{

    int iValue = 0;
    bool bRet = false;

    cout << "Enter the number of elements:\n";
    cin >> iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    cout<<"Data before sorting \n";

    aobj.Display();

    aobj.InsertionSort();

    cout<<"Data after sorting \n";

    aobj.Display();

    return 0;
}