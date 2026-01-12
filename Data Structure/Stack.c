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

int Push(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = (*first);
        *first = newn;
    }
}

int Pop(PPNODE first)
{
    PNODE temp = NULL;
    int iValue1 = 0;

    if(first == NULL)
    {
        printf("Stack Is Empty:\n");
        return -1;
    }
    else
    {
        temp = *first;

        iValue1 = temp->data;

        (*first) = (*first)->next;

        free(temp);

        return iValue1;
    }
}

int Peep(PNODE first)
{
    int iValue = 0;

    if(first == NULL)
    {
        printf("Stack Is Empty:\n");
        return -1;
    }
    iValue = first->data; 
    
    return iValue;
    
}

void Display(PNODE first)
{
    while(first!= NULL)
    {
        printf("| %d |\t\n",first->data);
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

    int iRet1 = 0,iRet2 = 0;

    Push(&head,51);
    Push(&head,41);
    Push(&head,31);
    Push(&head,21);
    Push(&head,11);

    Display(head);

    iRet1 = Count(head);

    printf("Number of nodes are: %d\n",iRet1);

    Pop(&head);

    Display(head);

    iRet1 = Count(head);

    printf("Number of nodes are: %d\n",iRet1);

    iRet2 = Peep(head);
    
    printf("top node from the stack is: %d\n",iRet2);

    return 0;
}