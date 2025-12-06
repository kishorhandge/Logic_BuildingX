#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

// Call by value

void Display(PNODE first)  //When we write PNODE means we can read it but cant Modify this list
{}

int Count(PNODE first)
{
    return 0;
}

//Call by address

void InsertFirst(PPNODE first,int no) //When we write PPNODE means we can change the actual head pointer
{}

void InsertLast(PPNODE first,int no)
{}

void InsertAtPose(PPNODE first ,int no,int pose)
{}


int main()
{
    PNODE head = NULL;

    Display(head);

    Count(head);

    InsertFirst(&head,11);

    InsertLast(&head ,21);
    InsertAtPose(&head ,51,5);


    return 0;
}