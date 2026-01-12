#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int enqueue(PPNODE first,PPNODE last, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
       ( *last)->next = newn;

        (*last) = (*last)->next;
    }
}

void dequeue(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else
    {
        temp = *first;

        (*first) = (*first)->next;

        free(temp);
    }
}

int Peep(PNODE first)
{
    int iValue = 0;

    if(first == NULL)
    {
        printf("Queue Is Empty:\n");
        return -1;
    }
    iValue = first->data; 
    
    return iValue;
    
}

void Display(PNODE first)
{
    while(first!= NULL)
    {
        printf("| %d |-",first->data);
        first = first->next;
    }
    printf("\n");
}

int Count(PNODE first)
{   
    int iCount = 0;

    while(first!= NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet1 = 0,iRet2 = 0;

    enqueue(&head,&tail,51);
    enqueue(&head,&tail,41);
    enqueue(&head,&tail,31);
    enqueue(&head,&tail,21);
    enqueue(&head,&tail,11);

    Display(head);

    iRet1 = Count(head);

    printf("Number of nodes are: %d\n",iRet1);

    dequeue(&head);

    Display(head);

    iRet1 = Count(head);

    printf("Number of nodes are: %d\n",iRet1);

    iRet2 = Peep(head);
    
    printf("top node from the Queue is: %d\n",iRet2);

    return 0;
}
