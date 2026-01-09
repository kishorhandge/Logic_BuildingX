////////////////////////////////////////
//
//Generalized  Data Structure  Library
//
//////////////////////////////////////

/*
-----------------------------------------------------------------------------------------
Type                    Name Of Class for node     Name Of Class for Functionality
-----------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode              SinglyLLL        Done 
Singly Circular         SinglyCLLnode              SinglyCLL
Doubly Linear           DoublyLLLnode              DoublyLLL        Done
Doubly Circular         DoublyCLLnode              DoublyCLL  
Stack                   StackNode                   Stack           Done
Queue                   Queuenode                   Queue           Done
------------------------------------------------------------------------------------------

*/

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
//                                                           
//        Singly Linear Linked List Using Generic Approach   
//                                                          
//////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class SinglyLLLnode
{
public:
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> *first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
     
        void DeleteAtPos(int );
     

};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout << "Object of SinglyLL gets created:" << "\n";

    this->first = NULL;
    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data Of node
//  Output:             Nothing
//  Discription:        Use To Insert node At First Position
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void  SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    if (first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->iCount++;
}

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if (this->iCount == 0) 
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)  
    {
        delete (this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;

        delete (temp);
    }

    this->iCount--;
}

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
  SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)  
    {
        delete (this->first);  
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);  

        temp->next = NULL;
    }

    this->iCount--;
}

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> *temp = NULL;

    temp = this->first;
    int iCnt = 0;

    for (iCnt = 1; iCnt <= this->iCount; iCnt++) 
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template<class T>
int  SinglyLLL<T> ::Count()
{

    return this->iCount;
}

template<class T>
void  SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);
    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }

    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;

        temp->next = newn;

        this->iCount++;
    }
}

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < (pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        delete (target);

        this->iCount--;
    }
}


////////////////////////////////////////////////////////////////////
//
//          Doubly Linear Linked List Using Generic Approach
//
//
////////////////////////////////////////////////////////////////////


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

/////////////////////////////////////////////////////////////////
//                                                           
//        Stack Using Generic Approach   
//                                                          
//////////////////////////////////////////////////////////////////

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



////////////////////////////////////////////////End Of Library///////////////////////////

int main()
{   
    SinglyLLL <int> *obj = new SinglyLLL <int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    obj->InsertAtPos(140, 3);

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    obj->DeleteAtPos(3);

    obj->Display();

    iRet = obj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    delete obj;

 //////////////////////////////////////////////////////////////////////////////////////////// 
 
    DoublyLLL <char> *dobj = new DoublyLLL <char>();

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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