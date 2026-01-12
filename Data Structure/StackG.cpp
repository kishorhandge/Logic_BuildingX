#include <iostream>
using namespace std;

template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

    Stacknode(T no)
    {
        data = no;
        next = NULL;
    }
};

template<class T>
class Stack
{
private:
    Stacknode<T> *first;
    int iCount;

public:
    Stack();

    T Push(T no);

    T Pop();

    T Peep();

    void Display();

    int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout << "Object of Stack gets created:\n";
    first = NULL;
    iCount = 0;
}

template<class T>
T Stack<T> :: Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = (first);
        first = newn;
    }

    iCount++;
}


template<class T>
T Stack<T> :: Pop()
    {
        Stacknode<T> *temp = NULL;

        T iValue1 = 0;

        if (first == NULL)
        {   
            cout<<"Stack Is Empty:\n";
            return -1;
        }
        else
        {
            temp = first;

            iValue1 = temp->data;

            (first) = (first)->next;

            delete(temp);

            return iValue1;
        }
        iCount--;
    }


template<class T>
T Stack<T> :: Peep()
{
    T iValue = 0;

    if (first == NULL)
    {
        printf("Stack Is Empty:\n");
        return -1;
    }
    iValue = first->data;

    return iValue;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
    cout << "\n";
}

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

int main()
{
    Stack<int> *sobj = new Stack<int>();

    int iRet1 = 0;

    sobj->Push(51);
    sobj->Push(41);
    sobj->Push(31);
    sobj->Push(21);
    sobj->Push(11);

    sobj->Display();

    iRet1 = sobj->Count();

    cout << "Number of Nodes are: " << iRet1 << "\n";

    iRet1 = sobj->Pop();

    cout<<"poped element is :"<<iRet1<<"\n";

    sobj->Display();

    iRet1 = sobj->Count();

    cout << "Number of Nodes are: " << iRet1 << "\n";

    iRet1 = sobj->Peep();

    cout << "Top Node from Stack is:" << iRet1 << "\n";

    return 0;
}