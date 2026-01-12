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

int iChoice = 0;
int Value1 = 0;
int Value2 = 0;
int iRet = 0;

while(1)        // unconditional loop
{
    cout<<"-----------------------------------------------------------------------------\n";

    cout<<"------------------Please Select The Option-----------------------------------\n";

    cout<<"1 : Insert new element in the First of Linear Linked List\n";
    cout<<"2 : Insert new element in the Last of Linear Linked List\n";
    cout<<"3 : Delete First element of the Linear Linked List\n";
    cout<<"4 : Delete Last element of the Linear Linked List\n";
    cout<<"5 : Display the element of the Linked List\n";
    cout<<"6 : Count the number of elements from the Linked List\n";
    cout<<"7 : Insert new element in the Middle Position Linear Linked List\n";
    cout<<"8 : Delete the element from the Middle of the Linear Linked List\n";
    cout<<"0 : Exit the application\n ";

    cin>>iChoice;

    cout<<"-----------------------------------------------------------------------------\n";

    switch(iChoice)
    {
        case 1:
            cout<<"Enter the element that you want to insert\n";
            cin>>Value1;
            obj->InsertFirst(Value1);
            cout<<"Element gets inserted At First successfully\n";
            break;
    cout<<"-----------------------------------------------------------------------------\n";

        case 2:
            cout<<"Enter the element that you want to insert\n";
            cin>>Value1;
            obj->InsertLast(Value1);
            cout<<"Element gets inserted At Last successfully\n";
            break;

    cout<<"-----------------------------------------------------------------------------\n";

        case 3:
            obj->DeleteFirst();    
            cout<<"First element deleted successfully\n";
            break;

    cout<<"-----------------------------------------------------------------------------\n";
        case 4:
            obj->DeleteLast();     
            cout<<"Last element deleted successfully\n";
            break;

    cout<<"-----------------------------------------------------------------------------\n";

        case 5:
            cout<<"Elements of the linked list are:\n";
            obj->Display();
            break;

    cout<<"-----------------------------------------------------------------------------\n";

        case 6:
            iRet = obj->Count();
            cout<<"Number of elements in linked list are: "<<iRet<<"\n";
            break;


    cout<<"-----------------------------------------------------------------------------\n";

        case 7:
            cout<<"Enter the element and position\n";
            cin>>Value1>>Value2;      
            obj->InsertAtPos(Value1, Value2);
            cout<<"Element gets inserted At the middle successfully\n";
            break;

    cout<<"-----------------------------------------------------------------------------\n";


        case 8:
            cout<<"Enter the Position from which you want to delete the element\n";
            cin>>Value2;
            obj->DeleteAtPos(Value2);
            cout<<"Element gets deleted At the middle successfully\n";
            break;

    cout<<"-----------------------------------------------------------------------------\n";

        case 0:
            cout<<"Thank You For Using Our Application......:\n";
            delete obj;
            return 0;

    cout<<"-----------------------------------------------------------------------------\n";

        default:
            cout<<"Please Enter the valid position:\n";


    }   //End of switch

}//End of while

     
    return 0;
}
