////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
#include<stdbool.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


//Maximum file size that we allow in our project
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 5

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Structures
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     BootBlock
//  Discription:        Holds the information to boot the OS
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     SuperBlock
//  Discription:        Holds the information about the file system
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     Inode
//  Discription:        Holds the information about the file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma pack(1)
struct Inode
{   
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
};
 
typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     FileTable
//  Discription:        Holds the information about the  opened file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;

};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     UAREA
//  Discription:        Holds the information about the process
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Global Variables or objects used in project
//   
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;

PINODE head = NULL;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      FunctionName: InitialiseUAREA()
//      Discription:  It is used to initialise UAREA members
//      Author:       Kishor Suryabhan Handge
//      Date:         13-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");

    int i = 0;

    for(i = 0;i < MAXOPENFILES;i++)
    {
        uareaobj.UFDT[i] = NULL;
    }

    printf("Marvellous CVFS: UAREA gets initialised succesfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      FunctionName:   InitializseSuperBlock()
//      Discription:    It is used to initialise SuperBlock members
//      Author:         Kishor Suryabhan Handge
//      Date:           13-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitializseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Marvellous CVFS: Super block gets initialised succesfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      FunctionName: CreateDILB()
//      Discription:  It is used to Create Linked List of inodes
//      Author:       Kishor Suryabhan Handge
//      Date:         13-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;

    PINODE newn = NULL;
    PINODE temp = head;
    
    for(i = 1; i<= MAXINODE; i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        strcpy(newn->FileName,"\0");
        newn->InodeNumber = i;
        newn->ActualFileSize = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)    //LL is empty
        {
            head = newn;
            temp = head;
        }
        else        //LL contains at least one node
        {
            temp->next = newn;
            temp = temp->next;
        }
        
    }

    printf("Marvellous CVFS : DILB created succesfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      FunctionName: StartAuxillaryDataInitialization()
//      Discription:  It is used to call all such functions which are used to initialise auxillary data
//      Author:       Kishor Suryabhan Handge
//      Date:         13-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialization()
{
    strcpy(bootobj.Information,"Booting Process Of Marvellous CVFS Is Done");

    printf("%s\n",bootobj.Information);

    InitializseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialised succesfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function Of The Project
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    char str[80] = {'\0'};
    char Command[4][20];
    int iCount = 0;


    StartAuxillaryDataInitialization();

    printf("--------------------------------------------------------------------------------------\n");
    printf("---------------------------Marvellous CVFS Started Succesfully------------------------\n");
    printf("--------------------------------------------------------------------------------------\n");

    while(1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\n Marvellous CVFS : >");
        fgets(str,sizeof(str),stdin);   //scanf("%s",str);


    }







    return 0;
}
