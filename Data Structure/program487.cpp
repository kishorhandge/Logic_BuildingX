///////////////////////////////////////////////////////////////
//
//Final Code Of Doubly Linear Linked List Using Generic Approach
//
//
/////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class DoublyLLLnode
{   
    public:
        T data;
        DoublyLLLnode* next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>

class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
        
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void  DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;

    }
    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;

    }
    this->iCount++;

}

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;

    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    int iCnt = 0;

    if(pos < 1 || pos >  this->iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        temp = this->first;

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;

        temp->next->prev = newn;

        temp->next = newn;

        newn->prev = temp;

        this->iCount++;
    }
}
template <class T>
void DoublyLLL<T> ::DeleteFirst()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)      
    {
        return;
    }
    else if(this->first->next == NULL)   
    {
        delete(this->first);
        this->first = NULL;
    }
    else                                 
    {
        this->first = this->first->next;

        delete(this->first->prev); 

        this->first->prev = NULL;

    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)     
    {
        return;
    }
    else if(this->first->next == NULL)   
    {
        delete(first);
        this->first = NULL;
    }
    else                                 
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;

    }

    this->iCount--;

}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos >  this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount +1)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;        

        temp->next = target->next;  

        target->next->prev = temp;

        delete(target);              

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    cout<<"\nNULL<=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int  DoublyLLL<T> ::Count()
{
    return this->iCount;
}

int  main()
{
    DoublyLLL <char> *dobj = new DoublyLLL <char>();

    int iRet = 0;

    dobj->InsertFirst('D');
    dobj->InsertFirst('C');
    dobj->InsertFirst('B');
    dobj->InsertFirst('A');

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number of DoublyLLLnodes are: "<<iRet<<"\n";

    dobj->InsertLast('E');
    dobj->InsertLast('F');
    dobj->InsertLast('G');

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number of DoublyLLLnodes are: "<<iRet<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number of DoublyLLLnodes are: "<<iRet<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number of DoublyLLLnodes are: "<<iRet<<"\n";

    dobj->InsertAtPos('I',3);

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number of DoublyLLLnodes are: "<<iRet<<"\n";

    dobj->DeleteAtPos(2);

    dobj->Display();

    iRet = dobj->Count();

    cout<<"Number ofDoublyLLLnodes are: "<<iRet<<"\n";


    delete dobj;


    return 0;
}