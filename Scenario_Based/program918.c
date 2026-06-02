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


//Time Complexity -> N+N/2

int MiddleElement(PNODE first)
{
    int iCount = 0;
    int mid = 0;
    PNODE temp = first;
    int iCnt = 0;

    while(first != NULL)    //N
    {
        iCount++;
        first = first->next;
    }

    mid = (iCount/2) + 1;

    first = temp;

    for(iCnt  = 1;iCnt < (mid);iCnt++) //N/2
    {
        first = first->next;
    }

    return(first->data);

}

//T.C = N/2

int MiddleElementX(PNODE first)
{
    PNODE slow = NULL;
    PNODE fast = NULL;

    fast = first;
    slow = first;

    while((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return (slow->data);
}

void InsertLast(PPNODE first ,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
       while(temp->next != NULL)
       {
            temp=temp->next;
       }
       temp->next = newn;
    }
}


void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int main()
{   
    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,101);
    InsertLast(&head,111);

    iRet = MiddleElementX(head);

    printf("Middle element is : %d\n",iRet);

    return 0;
}