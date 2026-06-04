#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


void InsertFirst(PPNODE first ,int no)
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
        newn->next = (*first);
        (*first) = newn;
    }
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

void Insert(PNODE first)
{
    int iCnt = 0;
    PNODE temp = NULL;
}

int main()
{   
    PNODE head = NULL;
    int temp = 0;

    int iRet = 0;
    int i = 0;
    int no = 0;
    int N = 0;

    printf("Enter the Number of element :\n");
    scanf("%d",&no);

    printf("Enter the element:\n");

    for(i = 1;i<= no;i++)
    {   
        scanf("%d",&N);

        temp = N;

        // if(N == temp)
        // {
        //     printf("Dupliacte element is not allowed:");
        //     return -1;
        // }
        if(N < temp)
        {
            InsertFirst(&head,N);
        }
        else if(N > temp)
        {
            InsertLast(&head,N);
        }
        
    }
    Display(head);

    return 0;
}