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
    void SelectionSort();

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
void ArrayX :: SelectionSort()
{   
    int i = 0, j = 0;
    int temp = 0;

    int Mini = 0;

    for(i = 0;i<iSize - 1;i++)
    {
        Mini = i;

        for(j = i +1;j<iSize;j++)
        {
            if(Arr[Mini] > Arr[j])
            {
                Mini = j;
            }
        }

        temp = Arr[i];
        Arr[i] = Arr[Mini];
        Arr[Mini] = temp;

        cout<<"\nData after pass : "<<i+1<<"\n";
        Display();

    }
     
}

/*
    Time Complexity of Selection Sort

    Worst Case Time Complexity  : O(n^2)

    Best Case Time Complexity   : O(n^2)
    (Even if array is already sorted, comparisons are same)

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

    aobj.SelectionSort();

    cout<<"Data after sorting \n";

    aobj.Display();

    return 0;
}