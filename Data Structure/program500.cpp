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
    void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SinglyLLL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Object of SinglyLL gets created:\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    if (this->first == NULL)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::InsertLast(T no)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = this->first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

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
        newn = new SinglyLLLnode<T>(no);
        temp = this->first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Singly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> *temp = NULL;
    SinglyLLLnode<T> *target = NULL;

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

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}
 

///////////////////////////////////////////////////////////////
//
//        Singly Circular Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////


template <class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyCL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SinglyCL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCL<T>::SinglyCL()
{
    cout << "Inside Constructor Of SinglyCL:\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;

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
        newn = new SinglyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

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
        delete temp;
        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;

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
        delete (target);
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::Display()
{
    SinglyCLLnode<T> *temp = this->first;

    if (first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;

    } while (temp != this->last->next);

    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////
//
//          Doubly Linear Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////


template <class T>
class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode<T> *next;
    DoublyLLLnode<T> *prev;

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
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DoublyLLL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Object Of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
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
        newn->prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        this->first->prev = NULL;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = this->first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

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
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;

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

        for (int iCnt = 1; iCnt < pos; iCnt++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////
//
//      Doubly Circular Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
public:
    T data;
    DoublyCLLnode<T> *next;
    DoublyCLLnode<T> *prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCL
{
private:
    DoublyCLLnode<T> *first;
    DoublyCLLnode<T> *last;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DoublyCL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCL<T>::DoublyCL()
{
    cout << "Object Of DoublyCL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;

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
        newn = new DoublyCLLnode<T>(no);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;

        delete temp;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;

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

        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::Display()
{
    if (this->first == NULL && this->last == NULL)
    {
        return;
    }

    DoublyCLLnode<T> *temp = this->first;

    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    } while (temp != this->last->next);

    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//
//        Stack Using Generic Approach
//
/////////////////////////////////////////////////////////////////

#include <iostream>
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Stack (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
Stack<T>::Stack()
{
    cout << "Stacks gets created successfully....:\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Push
//  Input:              Data
//  Output:             NA
//  Description:        Inserts element into Stack (LIFO)
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);
    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Pop
//  Input:              NA
//  Output:             Data
//  Description:        Removes and returns top element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
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
    delete temp;

    this->iCount--;
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Peep
//  Input:              NA
//  Output:             Data
//  Description:        Returns top element without removing it
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T Stack<T>::Peep()
{
    T Value = 0;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays Stack elements
//  Description:        Displays all elements of Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Stack<T>::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//
//        Queue Using Generic Approach
//
/////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class Queuenode
{
public:
    T data;
    Queuenode<T> *next;

    Queuenode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class Queue
{
private:
    Queuenode<T> *first;
    Queuenode<T> *last;
    int iCount;

public:
    Queue();
    void enqueue(T);
    T dequeue();
    void Display();
    int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Queue (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Queue
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
Queue<T>::Queue()
{
    cout << "Queues gets created successfully....:\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      enqueue
//  Input:              Data
//  Output:             NA
//  Description:        Inserts element into Queue (FIFO)
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if (this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      dequeue
//  Input:              NA
//  Output:             Data
//  Description:        Removes and returns front element from Queue
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T Queue<T>::dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue Is Empty:\n";
        return -1;
    }

    Value = this->first->data;
    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays Queue elements
//  Description:        Displays all elements of Queue
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T>::Display()
{
    Queuenode<T> *temp = this->first;

    if (this->first == NULL && this->last == NULL)
    {
        cout << "Queue Is Empty:\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of elements in Queue
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Queue<T>::Count()
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

SinglyCL<int> *kobj = new SinglyCL<int>();
    int iRet = 0;

    kobj->InsertFirst(51);
    kobj->InsertFirst(41);
    kobj->InsertFirst(31);
    kobj->InsertFirst(21);
    kobj->InsertFirst(11);

    kobj->Display();

    iRet = kobj->Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    kobj->InsertLast(101);
    kobj->InsertLast(111);

    kobj->Display();

    iRet = kobj->Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    kobj->InsertAtPos(345, 2);
    kobj->Display();

    kobj->DeleteAtPos(3);
    kobj->Display();

    delete kobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

DoublyCL<int> *obj = new DoublyCL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(41);
    obj->InsertFirst(31);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Number Of Nodes are: " << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);

    obj->Display();

    iRet = obj->Count();
    cout << "Number Of Nodes are: " << iRet << "\n";

    obj->InsertAtPos(113, 3);
    obj->Display();

    obj->DeleteAtPos(3);
    obj->Display();

    iRet = obj->Count();
    cout << "Number Of Nodes are: " << iRet << "\n";

    delete obj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(111.56789);

    qobj->Display();

    cout << "Number Of Elements in Queue are :" << qobj->Count() << "\n";

    cout << "Poped Element is :" << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number Of Elements in Queue are :" << qobj->Count() << "\n";

    cout << "Poped Element is :" << qobj->dequeue() << "\n";

    qobj->Display();

    cout << "Number Of Elements in Queue are :" << qobj->Count() << "\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout << "Number Of Elements in Queue are :" << qobj->Count() << "\n";

    delete qobj;

    return 0;
}