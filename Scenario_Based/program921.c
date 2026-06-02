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

bool CheckLoop(PNODE first)
{
    PNODE slow = NULL;
    PNODE fast = NULL;

    slow = first;
    fast = first;

    bool bFlag = false;

    while((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

int main()
{   
    PNODE head = NULL;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    bool bRet = false;
    int Pos = 4,i = 0;

    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    temp1 = head;
    temp2 = head;

    // temp1 = temp1->next->next->next;
    
    for(i = 1;i<Pos;i++)
    {
        temp1 = temp1->next;
    }
    // temp2 = temp2->next->next->next->next->next->next;

    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    //To Create The Loop
    temp2->next = temp1;

    bRet = CheckLoop(head);

    if(bRet == true)
    {
        printf("Loop is present \n");
    }
    else
    {
        printf("Loop is not present\n");
    }

    return 0;
}