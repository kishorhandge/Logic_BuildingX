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

bool CheckLoop(PNODE first)
{

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

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int iRet = 0;

    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    temp1 = head;
    temp2 = head;

    temp1 = temp1->next->next->next;
    temp2 = temp2->next->next->next->next->next->next;

    //To Create The Loop
    temp2->next = temp1;

    Display(head);

    return 0;
}