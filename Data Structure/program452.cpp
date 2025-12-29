//DoublyCL Linked List

// VERSION 1

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL()
        {
        cout<<"Object of DoublyLL gets created:"<<"\n";
        
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
        }

     void InsertFirst(int no)
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if((this->first == NULL) && (this->last == NULL))
        {
            this->first = newn;
            this->last = newn;
        }
        else
        {
            newn->next = this->first;

            this->first->prev = newn;

            this->first= newn; 
        }

        (this->last)->next = (this->first);
            
        (this->first)->prev = (this->last);

        this->iCount++;
     
    }

void InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(this->first == NULL)
        {
            this->first = newn;
            this->last = newn;
        }
        else
        {
            (this->last)->next = newn;

            newn->prev = (this->last);
            (this->last) = newn;

        }

        (this->last)->next = (this->first);
            
        (this->first)->prev = (this->last);

        this->iCount++;
}

void DeleteFirst()
{
    PNODE temp = NULL;

    temp = this->first;

    if((this->first == NULL) && (this->last == NULL) ) //iCount == 0  LL is Empty
    { 
        return;
    }
    else if((this->first) == (this->last))          //LL contains one Node
    {
        delete(this->first);

        this->first = NULL;
        this->last = NULL;
    }
    else
    {   
        temp = this->first;

        this->first = this->first->next;

        delete(this->first->prev);           //delete(temp);

        (this->last)->next = (this->first);
            
        (this->first)->prev = (this->last);
        

    }
    this->iCount--;
}

void DeleteLast()
{
     PNODE temp = NULL;

    temp = this->first;

    if((this->first == NULL) && (this->last == NULL) ) //iCount == 0  LL is Empty
    { 
        return;
    }
    else if((this->first) == (this->last))          //LL contains one Node
    {
        delete(this->first);

        this->first = NULL;
        this->last = NULL;
    }
    else
    {   
        this->last = this->last->prev;

        delete(this->last->next);           //delete(first->prev)

        (this->last)->next = (this->first);
            
        (this->first)->prev = (this->last);
        

    }
    this->iCount--;
}

void Display()
{   

    if(first == NULL && last == NULL) // LL is Empty
    {
        cout<<"Linked List Empty"<<"\n";
        return;
        
    }

    PNODE temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;
    } while(temp != (last)->next);

   cout<<"NULL\n";
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
        
        temp->next->prev = newn;

        temp->next = newn;

        newn->prev = temp;

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

        target->next->prev = temp;      //temp->next->next->prev = temp;

        free(target);                   //delete(temp->next->prev)

        this->iCount--;

    }
}

};

int main()
{
    DoublyCL obj;
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


    return 0;
}