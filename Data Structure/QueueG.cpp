#include <iostream>
using namespace std;

template<class T>

class Queuenode
{   
    public:
        T data;
        struct Queuenode *next;

    Queuenode(T no)
    {
        data = no;
        next = NULL;
    }
};

template<class T>
class Queue
{
private:
    Queuenode<T> *first;
    int iCount;

public:
    Queue();

    T enqueue(T no);

    T dequeue();

    T Peep();

    void Display();

    int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout << "object of Queue gets created:\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
T Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    Queuenode<T> *temp = NULL;

    newn = new Queuenode<T>(no);

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    Queuenode<T> *temp = NULL;

    T iValue1 = 0;

    if (first == NULL)
    {
        cout << "Queue is Empty:\n";
        return -1;
    }
    else
    {
        temp = first;

        iValue1 = temp->data;

        (first) = (first)->next;

        delete (temp);

        return iValue1;
    }
    iCount--;
}

template<class T>
T Queue<T> :: Peep()
{
    T iValue = 0;

    if (first == NULL)
    {
        printf("Queue Is Empty:\n");
        return -1;
    }
    iValue = first->data;

    return iValue;
}

template<class T>
void Queue<T> ::Display()
{
    Queuenode<T> *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-";
        temp = temp->next;
    }
    cout << "\n";
}

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

int main()
{
    Queue<int> *qobj = new Queue<int>();
    int iRet1 = 0;

    qobj->enqueue(51);
    qobj->enqueue(41);
    qobj->enqueue(31);
    qobj->enqueue(21);
    qobj->enqueue(11);

    qobj->Display();

    iRet1 = qobj->Count();

    cout << "Number of Nodes are: " << iRet1 << "\n";

    iRet1 = qobj->dequeue();

    cout << "Dequeued elements is :" << iRet1 << "\n";

    qobj->Display();

    iRet1 = qobj->Count();

    cout << "Number of Nodes are: " << iRet1 << "\n";

    iRet1 = qobj->Peep();

    cout << "Top Node from Queue is:" << iRet1 << "\n";

    return 0;
}