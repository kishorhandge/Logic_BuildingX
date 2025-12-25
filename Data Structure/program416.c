#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)     //LL is Empty
    {
        *first = newn;
        *last = newn;

    }
    else                                    //LL contains one or more Node
    {
        newn->next = (*first);
        (*first)->prev = newn;
        (*first) = newn;
    }

    (*last)->next = (*first);
    (*first)->prev = (*last);
     

}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)     //LL is Empty
    {
        *first = newn;
        *last = newn;

    }
    else                                    //LL contains one or more Node
    {
        
    }

    (*last)->next = (*first);
    (*first)->prev = (*last);
     
}

void DeleteFirst(PPNODE first,PPNODE last)
{

}

void DeleteLast(PPNODE first,PPNODE last)
{

}
void InsertAtPos(PPNODE first,PPNODE last,int pos ,int no)
{
    
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{

}

void Display(PNODE first,PNODE last)
{   
    //IMPORTANT

    if(first == NULL && last == NULL) // LL is Empty
    {
        printf("Linked List Empty\n");
        return;
    }

    printf("<=>");

    do
    {
        printf("| %d | <=>",first->data);
        first= first->next;

    } while (first != last->next);

    printf("\n");
    
}

int Count(PNODE first,PNODE last)
{   
    if(first == NULL && last == NULL) // LL is Empty
    {
        return 0;
    }

    int iCount = 0;
    do
    {
        iCount++;
        first= first->next;

    } while (first != last->next);

    return iCount;
     
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;
/*
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,41);
    InsertFirst(&head,&tail,31);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
*/

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of Nodes are:%d\n",iRet);



    return 0;
}