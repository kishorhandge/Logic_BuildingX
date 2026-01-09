///////////////////////////////////////////////////////////////
//
// Final Code Of Stack Using Generic Approach
//
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)

template <class T>

class Stacknode
{
public:
    T data;
    Stacknode<T> *next;

    Stacknode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>

class Stack
{
private:
    Stacknode<T> *first;
    int iCount;

public:
    Stack();
    void Push(T);
    T Pop();
    T Peep();
    void Display();
    int Count();
};

template <class T>

Stack<T>::Stack()
{
    cout << "Stacks gets created successfully....:\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>

void Stack<T>::Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;

    this->first = newn;

    this->iCount++;
}

template <class T>

T Stack<T>::Pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    delete (temp);

    this->iCount--;

    return Value;
}

template <class T>

T Stack<T>::Peep()
{
    T Value = 0;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return T();
    }

    Value = this->first->data;

    return Value;
}

template <class T>

void Stack<T>::Display()
{
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}

template <class T>

int Stack<T>::Count()
{
    return this->iCount;
}

int main()
{
    Stack<int> *sobj = new Stack<int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while (1) // unconditional loop
    {
        cout << "-----------------------------------------------------------------------------\n";

        cout << "------------------Please Select The Option-----------------------------------\n";

        cout << "1 : Insert new element in the Stack\n";
        cout << "2 : Remove the element from the Stack\n";
        cout << "3 : Display Top element from the Stack\n";
        cout << "4 : Display the elements of the Stack\n";
        cout << "5 : Count the number of elements from the Stack\n";
        cout << "0 : Exit the application\n";

        cin >> iChoice;

        cout << "-----------------------------------------------------------------------------\n";

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert\n";
            cin >> Value;
            sobj->Push(Value);
            cout << "Element gets inserted successfully\n";
            break;

        case 2:
            iRet = sobj->Pop();
            cout << "Element removed from Stack is : " << iRet << "\n";
            break;

        case 3:
            iRet = sobj->Peep();
            cout << "Top Element from Stack is : " << iRet << "\n";
            break;

        case 4:
            cout << "Elements of the Stack are:\n";
            sobj->Display();
            break;

        case 5:
            cout << "Number of elements in Stack are : " << sobj->Count() << "\n";
            break;

        case 0:
            cout << "Thank You For Using Our Application\n";
            delete sobj;
            return 0;

        default:
            cout << "Please Enter a valid option\n";

        }//End of switch


    }//End of while

    return 0;
}