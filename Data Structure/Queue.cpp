#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Queue
{
private:
    PNODE first;
    int iCount;

public:
    Queue()
    {
        cout << "qobject of Queue gets created:\n";
        first = NULL;
        iCount = 0;
    }

    int enqueue(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newn;
        }

        iCount++;
    }

   int dequeue()
    {
        PNODE temp = NULL;

        int iValue1 = 0;

        if (first == NULL)
        {   
            cout<<"Queue is Empty:\n";
            return -1 ;
        }
        else
        {
            temp = first;

            iValue1 = temp->data;

            (first) = (first)->next;

            delete(temp);

            return iValue1;
        }
        iCount--;
    }

    int Peep()
    {
        int iValue = 0;

        if (first == NULL)
        {
            printf("Stack Is Empty:\n");
            return -1;
        }
        iValue = first->data;

        return iValue;
    }

    void Display()
    {   
        PNODE temp = NULL;

        temp = first;

        while (temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-";
            temp = temp->next;
        }
        cout<<"\n";
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    Queue qobj;
    int iRet1 = 0;

    qobj.enqueue(51);
    qobj.enqueue(41);
    qobj.enqueue(31);
    qobj.enqueue(21);
    qobj.enqueue(11);

    qobj.Display();

    iRet1 = qobj.Count();

    cout<<"Number of Nodes are: "<<iRet1<<"\n";

    iRet1 = qobj.dequeue();

    cout<<"Dequeued elements is :"<<iRet1<<"\n";

    qobj.Display();

    iRet1 = qobj.Count();

    cout<<"Number of Nodes are: "<<iRet1<<"\n";

    iRet1 = qobj.Peep();

    cout<<"Top Node from Queue is:"<<iRet1<<"\n";


    return 0;
}