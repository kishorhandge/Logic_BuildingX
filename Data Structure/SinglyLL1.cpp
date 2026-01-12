#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    node<T>* next;
};

template <class T>
using NODE = node<T>;

template <class T>
using PNODE = node<T>*;

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
        PNODE<T> newn = new NODE<T>;

        newn->data = no;
        newn->next = first;
        first = newn;

        iCount++;
    }

    void InsertLast(T no)
    {
        PNODE<T> newn = new NODE<T>;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            PNODE<T> temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }

        iCount++;
    }

    void Display()
    {
        PNODE<T> temp = first;

        while(temp != NULL)
        {
            cout << "| " << temp->data << " |-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SinglyLL<int> obj;

    obj.InsertFirst(51);
    obj.InsertFirst(41);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();

    return 0;
}

/*
    Variables like iCount and pos represent counts and positions, 
    which are always integers.
    void does not return anything so it will not be T.
*/
