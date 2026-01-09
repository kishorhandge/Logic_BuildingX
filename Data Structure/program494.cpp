///////////////////////////////////////////////////////////////
//
//Final Code Of Stack Using Generic Approach
//
//
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>

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

template<class T>

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

template<class T>

Stack<T> :: Stack()
{
    cout<<"Stacks gets created successfully....:\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>

void  Stack<T> ::Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;


    this->first = newn;

    this->iCount++;
} 

template<class T>

T  Stack<T> ::Pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    delete(temp);

    this->iCount--;

    return Value;

} 

template<class T>

T Stack<T> :: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

template<class T>

void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return;
    }

    while(temp!= NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>

int  Stack<T> ::Count()
{
    return this->iCount;
}


int main()
{
    Stack <char>*sobj = new Stack<char>();

    sobj->Push('A');
    sobj->Push('B');
    sobj->Push('C');
    sobj->Push('D');

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Return Value Of Peep is :"<<sobj->Peep()<<"\n";

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped Element is :"<<sobj->Pop()<<"\n";

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped Element is :"<<sobj->Pop()<<"\n";

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    sobj->Push('E');

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    delete sobj;
    
    return 0; 
}