///////////////////////////////////////////////////////////////
//
// Final Code Of Doubly Linear Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)

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

int main()
{
    DoublyLLL<int> *obj = new DoublyLLL<int>();

    obj->InsertFirst(30);
    obj->InsertFirst(20);
    obj->InsertFirst(10);

    obj->InsertLast(40);
    obj->InsertLast(50);

    obj->Display();

    cout << "Count: " << obj->Count() << "\n";

    obj->InsertAtPos(25, 3);
    obj->Display();

    obj->DeleteAtPos(3);
    obj->Display();

    delete obj;
    return 0;
}
