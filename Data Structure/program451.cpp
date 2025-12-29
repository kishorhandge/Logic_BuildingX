//SinglyCL Linked List

// VERSION 1

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCL
{
    public:
        PNODE first;
        PNODE last;
        int iCount;


    SinglyCL()
    {
        cout<<"Object of SinlyCL gets created:"<<"\n";

        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if((this->first == NULL) && (this->last == NULL))
        {
            this->first = newn;
            this->last = newn;

            (this->last)->next = (this->first);

        }
        else
        {
            newn->next = (this->first);

            this->first= newn;

            (this->last)->next = (this->first);

        }

        this->iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        if((this->first == NULL) && (this->last == NULL))
        {
            this->first = newn;
            this->last = newn;

            (this->last)->next = (this->first);

        }
        else
        {
            this->last->next = (newn);
            this->last = newn;

            (this->last)->next = (this->first);

        }
        
        this->iCount++;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;

        if((this->first == NULL) && (this->last ==  NULL))      // (iCount == 0)
        {
            return;
        }
        else if((this->first) == (this->last))
        {
            delete(this->first);                      //delete(last)
            this->first = NULL;
            this->last = NULL;
        }
        else 
        {
            temp = this->first;

            this->first = this->first->next;

            delete(temp);

            (this->last)->next = (this->first);
        }
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if((this->first == NULL) && (this->last ==  NULL))      // (iCount == 0)
        {
            return;
        }
        else if(this->first == this->last)
        {
            delete(this->first);                      //delete(last)
            this->first = NULL;
            this->last = NULL;
        }
        else 
        {
            temp = this->first;

            while(temp->next != (this->last))
            {
                temp = temp->next;
            }

            delete(this->last);                    //free(temp->next);

            this->last = temp;

            (this->last)->next = (this->first);
        }
    }

    void Display()
    {   
        if(first == NULL && last == NULL) // LL is Empty
        {
        cout<<"Linked List Empty"<<"\n";
        return;
        
        }

        do
        {
        cout<<"| "<<this->first->data<<" |"<<"->";
        this->first = this->first->next;

        }while(this->first != (this->last)->next);

        cout<<"\n";
        
    }

    int Count()
    {
        return this->iCount;
    }

    void InsertAtPos(int no,int pos)
    {
    PNODE newn = NULL;
    PNODE temp = NULL;
     
    int iCnt = 0;

    newn = new NODE;
    
    newn->data = no;
    newn->next = NULL;

    if(pos < 1 || pos > this->iCount +1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1 )
    {
        InsertFirst(no);
    }
    else if(pos ==  this->iCount +1)
    {
        InsertLast(no);
    }
    else
    {
        temp = (this->first);

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next; 
         
        temp->next = newn;

        this->iCount++;

    }

}

void DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos ==  this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = (this->first);

        for(iCnt = 1;iCnt < pos-1;iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;        

        temp->next = target->next;      //temp->next = temp->next->next

        free(target);

        this->iCount--;

    }
}
    
};

int main()
{
    SinglyCL obj;

    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(41);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";

    obj.InsertAtPos(150,3);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(3);

    obj.Display();

    iRet = obj.Count();

    cout<<"Number Of Nodes are:"<<iRet<<"\n";
}