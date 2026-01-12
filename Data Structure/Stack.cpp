#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Stack
{
private:
    PNODE first;
    int iCount;

public:
    Stack()
    {
        cout << "Object of Stack gets created:\n";
        first = NULL;
        iCount = 0;
    }

    int Push(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = (first);
            first = newn;
        }

        iCount++;
    }

    int Pop()
    {
        PNODE temp = NULL;

        int iValue1 = 0;

        if (first == NULL)
        {   
            cout<<"Stack Is Empty:\n";
            return -1;
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
            cout<<"|\t"<<temp->data<<"\t|\n";
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
    Stack obj;
    int iRet1 = 0;

    obj.Push(51);
    obj.Push(41);
    obj.Push(31);
    obj.Push(21);
    obj.Push(11);

    obj.Display();

    iRet1 = obj.Count();

    cout<<"Number of Nodes are: "<<iRet1<<"\n";

    iRet1 = obj.Pop();

    cout<<"Poped Element is :"<<iRet1<<"\n";

    obj.Display();

    iRet1 = obj.Count();

    cout<<"Number of Nodes are: "<<iRet1<<"\n";

    iRet1 = obj.Peep();

    cout<<"Top Node from Stack is:"<<iRet1<<"\n";


        return 0;
}