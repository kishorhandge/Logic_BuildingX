#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))   //@
    {
        *first = newn;
        *last = newn;

        (*last)->next = (*first);
    }
    else
    {   
        newn->next = (*first);
        *first = newn;
        
        (*last)->next = (*first);           //@
    }
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))  //@
    {
        *first = newn;
        *last = newn;
        
        (*last)->next = (*first);
    }
    else
    {   
        (*last)->next = newn;           //@
        (*last) = newn;                 //@

        (*last)->next = (*first);
    }
}

void DeleteFirst(PPNODE first,PPNODE last)
{   
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         //CASE 1
    {
        return;
    }
    else if(*first == *last )                       //CASE 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                            //CASE 3    
    {
        temp = *first;

        (*first) = (*first)->next;          //temp = temp->next
        free(temp);

        (*last)->next = (*first);
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{   
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         //CASE 1
    {
        return;
    }
    else if(*first == *last )                       //CASE 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != (*last))
        {
            temp = temp->next;
        }

        free(*last);        // free(temp->next);

        (*last) = temp;

        (*last)->next = (*first);
    }
}

void Display(PNODE first,PNODE last)
{
    do
    {
        printf("| %d |->",first->data);
        first= first->next;

    } while (first != last->next);

    printf("\n");
    
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first= first->next;

    } while (first != last->next);

    return iCount;
}

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iSize = 0;
    int iCnt = 0;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    iSize = Count(*first,*last);

    if((pos < 1 )|| (pos > iSize + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,last,no);

    }
    else
    {
        temp = *first;

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;

        temp->next = newn;


    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{

}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;              //@

    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    DeleteFirst(&head,&tail);

    Display(head,tail);

    DeleteLast(&head,&tail);

    Display(head,tail);

    InsertAtPos(&head,&tail,113,3);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number Of Nodes are : %d\n",iRet);


    return 0;
}