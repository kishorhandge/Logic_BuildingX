

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
    void BubbleSortEfficient();
    void BubbleSortEfficientX(int iOption);
};

ArrayX ::ArrayX(int no)
{
    cout << "Inside Constructor" << "\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX ::~ArrayX()
{
    cout << "Inside Destructor:" << "\n";
    delete[] Arr;
}
void ArrayX ::Accept()
{
    int iCnt = 0;

    cout << "Enter the elements:" << "\n";
    cin >> Arr[iCnt];

    for (iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];

        if (Arr[iCnt - 1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }
}
void ArrayX ::Display()
{
    int iCnt = 0;

    cout << "Elements of Array are:" << "\n";

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << Arr[iCnt] << "\t";
    }
    cout << "\n";
}

bool ArrayX ::CheckSorted()
{
    int i = 0;

    bool bFlag = true;

    for (i = 0; i < iSize - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

// 21 15 18 16 11
void ArrayX ::BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;
    int pass = 0;
    int Time = 0;

    if (Sorted == true) // Important filter
    {
        return;
    }

    Time = 1;

    for (i = 0, pass = 1; i < iSize - 1; i++, pass++) // Outer loop
    {
        for (j = 0; j < iSize - 1 - i; j++, Time++) // Inner
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout << "\nData after pass : " << i + 1 << "\n";
        Display();
    }

    cout << "Number of passes for bubbel sort: " << pass << "\n";
    cout << "Total number of iterations : " << Time << "\n";

    Sorted = true;
}

// 21 15 18 16 11
void ArrayX ::BubbleSortEfficient()
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    // if(Sorted == true)  //Important filter
    // {
    //     return;
    // }

    bFlag = true;

    for (i = 0; (i < iSize - 1) && (bFlag == true); i++) // Outer loop
    {
        bFlag = false;

        for (j = 0; j < iSize - 1 - i; j++) // Inner
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout << "\nData after pass : " << i + 1 << "\n";
        Display();
    }
    cout << "Number of passes for bubbel sort: " << i << "\n";

    Sorted = true;
}

// 1 : increasing
// 2 : decreasing
void ArrayX ::BubbleSortEfficientX(int iOption = 1)
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    if (iOption < 1 || iOption > 2)
    {
        cout << "Invalid option for sorting: " << "\n";
        cout << "1 : Increasing \n";
        cout << "2 : Decreasing \n";
    }

    // if(Sorted == true)  //Important filter
    // {
    //     return;
    // }

    bFlag = true;

    for (i = 0; (i < iSize - 1) && (bFlag == true); i++) // Outer loop
    {
        bFlag = false;

        for (j = 0; j < iSize - 1 - i; j++) // Inner
        {
            if (iOption == 1)       //increasing
            {
                if (Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
            else if (iOption == 2)       //decreasing
            {
                if (Arr[j] < Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }

        cout << "\nData after pass : " << i + 1 << "\n";
        Display();
    }
    cout << "Number of passes for bubbel sort: " << i << "\n";

    Sorted = true;
}

int main()
{

    int iValue = 0;
    bool bRet = false;

    cout << "Enter the number of elements:\n";
    cin >> iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    cout << "Data before sorting \n";

    aobj.Display();

    // 1 : increasing
    // 2 : decreasing
    aobj.BubbleSortEfficientX(2);

    cout << "Data after sorting \n";

    aobj.Display();

    return 0;
}