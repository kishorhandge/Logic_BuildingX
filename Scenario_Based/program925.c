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

//Time Complexity -->N
//Space Complexity-->1


//Reversal linked list alogo
void Reverse(PPNODE first)
{
    PNODE Prevoius = NULL;
    PNODE Next = NULL;
    PNODE Current = NULL;

    if(*first == NULL)
    {
        return;
    }

    Current = *first;

    while(Current != NULL)
    {
        Next = Current->next;
        Current->next = Prevoius;
        Prevoius = Current;
        Current = Next;
    }

    *first = Prevoius;

}

int main()
{   
    PNODE head = NULL;

    bool bRet = false;

    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,51);
    InsertLast(&head,101);

    Display(head);

    Reverse(&head);

    printf("Linked list After reverse:\n");

    Display(head);

    return 0;
}