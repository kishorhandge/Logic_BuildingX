#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    node<T> *next;
};

template <class T>
using PNODE = node<T> *;

template <class T>
class SinglyLL
{
private:
    PNODE<T> first;
    int iCount;

public:
    SinglyLL()
    {
        cout << "Object of SinglyLL gets created\n";
        first = NULL;
        iCount = 0;
    }

    void InsertFirst(T no)
    {
        PNODE<T> newn = new node<T>;

        newn->data = no;
        newn->next = first;
        first = newn;

        iCount++;
    }

    void InsertLast(T no)
    {
        PNODE<T> newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            PNODE<T> temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    void DeleteFirst()
    {
        if (first == NULL)
            return;

        PNODE<T> temp = first;
        first = first->next;
        delete temp;

        iCount--;
    }

    void DeleteLast()
    {
        if (first == NULL)
            return;

        if (first->next == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            PNODE<T> temp = first;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }

    void InsertAtPos(T no, int pos)
    {
        if (pos < 1 || pos > iCount + 1)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE<T> newn = new node<T>;
            newn->data = no;

            PNODE<T> temp = first;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
    }

    void DeleteAtPos(int pos)
    {
        if (pos < 1 || pos > iCount)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE<T> temp = first;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            PNODE<T> target = temp->next;
            temp->next = target->next;
            delete target;

            iCount--;
        }
    }

    void Display()
    {
        PNODE<T> temp = first;
        while (temp != NULL)
        {
            cout << "| " << temp->data << " |-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyLL<int> obj;

    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(41);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();

    cout << "Number Of Nodes are: " << iRet;

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.Count();

    cout << "Number Of Nodes are: " << iRet;

    obj.DeleteFirst();

    iRet = obj.Count();

    cout << "Number Of Nodes are: " << iRet;

    obj.DeleteLast();

    iRet = obj.Count();

    cout << "Number Of Nodes are: " << iRet;

    obj.InsertAtPos(150, 2);
    obj.Display();

    iRet = obj.Count();

    cout << "Number Of Nodes are: " << iRet;

    obj.DeleteAtPos(3);
    obj.Display();

    return 0;
}

/*
    Variables like iCount and pos represent counts and positions,
    which are always integers.
    void does not return anything so it will not be T.
*/