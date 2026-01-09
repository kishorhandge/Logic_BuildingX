#include<iostream>
using namespace std;

#pragma pack(1)

class Stacknode
{
    public:
        int data;
        Stacknode *next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};


class Stack
{
    private:
        Stacknode *first;
        int iCount;

    public:
        Stack();
        void Push(int);     //InsertFirst
        int Pop();          //DeleteFirst
        int Peep();
        void Display();
        int Count();
};

Stack :: Stack()
{
    cout<<"Stacks gets created successfully....:\n";
    this->first = NULL;
    this->iCount = 0;
}

void  Stack ::Push(int no)
{
    Stacknode *newn = NULL;

    newn = new Stacknode(no);

    newn->next = this->first;


    this->first = newn;

    this->iCount++;
}   

int  Stack ::Pop()
{
    int Value = 0;
    Stacknode *temp = this->first;

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

int Stack :: Peep()
{
    int Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

void Stack :: Display()
{
    Stacknode *temp = this->first;

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

int  Stack ::Count()
{
    return this->iCount;
}


int main()
{
    Stack *sobj = new Stack();

    sobj->Push(11);
    sobj->Push(21);
    sobj->Push(51);
    sobj->Push(111);

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

    sobj->Push(121);

    sobj->Display();

    cout<<"Number Of Elements in Stack are :"<<sobj->Count()<<"\n";

    delete sobj;
    
    return 0; 
}