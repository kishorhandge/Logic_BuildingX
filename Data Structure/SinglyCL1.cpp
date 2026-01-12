#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

template <class T>

class SinglyCL
{
    private:
    struct node<T> *first;
    struct node<T> *last;
    int iCount;

    public:
        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InasertAtPos(T no,int pos);
        void DeleteAtPos(int pos);

};

template<class T>
SinglyCL<T> :: SinglyCL()
{
        cout << "Inside Constructor Of SinglyLL:\n";

        first = NULL;
        last = NULL;
        iCount = 0;
    
}
template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;  

        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;

            last->next = first;
        }
        else
        {
            newn->next = first;

            first = newn;

            last->next = first;
        }

        iCount++;

    }

template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
       struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;  

        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }

        last->next = first;

        iCount++;
    }
template<class T>
void SinglyCL<T> :: DeleteFirst()
    {
        PNODE temp = NULL;

        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if((first) == (last))
        {
            delete(first);

            first = NULL;
            last = NULL;
        }
        else
        {
            temp = first;

            first = first->next;

            delete(last->next);

            last->next = first;
        }
        
        iCount--;
    }
template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if((first) == (last))
        {
            delete(first);

            first = NULL;
            last = NULL;
        }
        else
        {
            temp = first;

           while(temp->next != last)
           {
                temp = temp->next;
           }

           delete(last);
           last = temp;

            last->next = first;
        }

        iCount--;
    }

template <class T>
void SinglyCL<T>::Display()
    {   
       if(first == NULL && last == NULL)
       {
            return;
       }

        struct node<T> *temp = first;

        do
        {
          cout<<"| "<<temp->data<<" |<=>";
          temp = temp->next;

        }while(temp != last->next);

        cout<<"\n";
    }
template <class T>
int SinglyCL<T>::Count()
    {
        return iCount;
    }

int main()
{
    SinglyCL<int> obj;

    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(41);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are :"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are :"<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are :"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are :"<<iRet<<"\n";


    return 0;
}

/*
    Variables like iCount and pos represent counts and positions, 
    which are always integers.
    void does not return anything so it will not be T.
*/
