///////////////////////////////////////////////////////////////
//
// Final Code Of Singly Circular Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)

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

int main()
{
    SinglyCL<int> *obj = new SinglyCL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(41);
    obj->InsertFirst(31);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);

    obj->Display();

    iRet = obj->Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj->InsertAtPos(345, 2);
    obj->Display();

    obj->DeleteAtPos(3);
    obj->Display();

    delete obj;
    return 0;
}
