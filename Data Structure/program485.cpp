#include <iostream>
using namespace std;

#pragma pack(1)

template<class T>
class node
{
public:
    T data;
    node<T> *next;

    node(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyLLL
{
    private:
        node<T> *first;
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

template<class T>
void  SinglyLLL<T> :: InsertFirst(T no)
{
    node<T> *newn = NULL;

    newn = new node<T>(no);

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
    node<T> *newn = NULL;
    node<T> *temp = NULL;

    newn = new node<T>(no);

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
    node<T> *temp = NULL;

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
    node<T> *temp = NULL;

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
    node<T> *temp = NULL;

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
    node<T> *newn = NULL;
    node<T> *temp = NULL;

    newn = new node<T>(no);
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
    node<T> *temp = NULL;
    node<T> *target = NULL;

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


int main()
{
    SinglyLLL <int> *sobj = new SinglyLLL <int>();
    int iRet = 0;

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    sobj->DeleteFirst();

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    sobj->DeleteLast();

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    sobj->InsertAtPos(140, 3);

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    sobj->DeleteAtPos(3);

    sobj->Display();

    iRet = sobj->Count();

    cout << "Number of Nodes are:" << iRet << "\n";

    return 0;
}