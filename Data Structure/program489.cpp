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
Singly Circular         SinglyCLLnode              SinglyCLL        Done
Doubly Linear           DoublyLLLnode              DoublyLLL        Done
Doubly Circular         DoublyCLLnode              DoublyCLL        Done
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

//------------------------------------------------------------------------------------------------------------------------//

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

//------------------------------------------------------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////
//
//          Singly Circular Linked List Using Generic Approach
//
//
////////////////////////////////////////////////////////////////////


#pragma pack(1)

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>

class SinglyCL
{
private:
    struct SinglyCLLnode<T> *first;
    struct SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    cout << "Inside Constructor Of SinglyLL:\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> *newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;

        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> *newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> *temp = NULL;
    struct SinglyCLLnode<T> *newn = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    struct SinglyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if ((this->first) == (this->last))
    {
        delete (this->first);

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;

        delete (this->last->next);

        this->last->next = this->first;
    }

    this->iCount--;
}
template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if ((this->first) == (this->last))
    {
        delete (this->first);

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next != this->last)
        {
            temp = temp->next;
        }

        delete (this->last);
        this->last = temp;

        this->last->next = this->first;
    }

    this->iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> *temp = NULL;
    struct SinglyCLLnode<T> *target = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position" << "\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        delete (target);
        this->iCount--;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    if (first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> *temp = this->first;

    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;

    } while (temp != this->last->next);

    cout << "\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return this->iCount;
}
//------------------------------------------------------------------------------------------------------------------------//

//////////////////////////////////////////////////////////////////
//
//          Doubly Circular Linked List Using Generic Approach
//
//
///////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCL
{
private:
    struct DoublyCLLnode<T> *first;
    struct DoublyCLLnode<T> *last;
    int iCount;

public:
    DoublyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    cout << "Object Of DoublyCL gets created" << "\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct DoublyCLLnode<T> *newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct DoublyCLLnode<T> *newn = NULL;
    struct DoublyCLLnode<T> *temp = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> *newn = NULL;

    struct DoublyCLLnode<T> *temp = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyCLLnode<T> *newn = NULL;

        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
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
void DoublyCL<T>::DeleteFirst()
{
    struct DoublyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete (this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete (this->first->prev);

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}
template <class T>
void DoublyCL<T>::DeleteLast()
{
    struct DoublyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete (this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;

        delete (this->last->next);

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> *temp = NULL;

    struct DoublyCLLnode<T> *target = NULL;

    temp = this->first;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        target->next->prev = temp;

        delete (target);

        this->iCount--;
    }
}
template <class T>
void DoublyCL<T>::Display()
{
    if (this->first == NULL && this->last == NULL)
    {
        return;
    }

    struct DoublyCLLnode<T> *temp = this->first;

    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    } while (temp != this->last->next);

    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return this->iCount;
}


////////////////////////////////////////////////End Of Library///////////////////////////

int main()
{

    return 0;
}