///////////////////////////////////////////////////////////////
//
// Final Code Of Singly Linear Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

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

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();

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
