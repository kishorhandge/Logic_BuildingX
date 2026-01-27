////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>                     // Provides printf(), scanf()
#include<stdlib.h>                    // Provides malloc(), free()
//#include<unistd.h>                  // POSIX system calls (kept commented as in original)
#include<stdbool.h>                   // Provides boolean type
#include<string.h>                    // Provides string handling functions

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


//Maximum file size that we allow in our project
#define MAXFILESIZE 50                 // Maximum size allowed for one virtual file

#define MAXOPENFILES 20                // Maximum number of files that can be opened at a time

#define MAXINODE 5                     // Maximum number of inodes (files) in CVFS

#define READ 1                         // Read permission flag
#define WRITE 2                        // Write permission flag
#define EXECUTE 4                      // Execute permission flag

#define START 0                        // Used to start reading/writing from beginning
#define CURRENT 1                      // Used to read/write from current position
#define END 2                          // Used to read/write from end of file

#define EXECUTE_SUCCESS 0              // Indicates successful execution of operation

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
    char Information[100];             // Stores basic information about CVFS at boot time
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     SuperBlock
//  Discription:        Holds the information about the file system
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;                   // Total number of inodes created
    int FreeInodes;                    // Number of inodes currently free
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     Inode
//  Discription:        Holds the information about the file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////



#pragma pack(1)                       // Prevents extra padding in structure
struct Inode
{   
    char FileName[20];                 // Name of the file
    int InodeNumber;                  // Unique number for each file
    int FileSize;                     // Maximum size of file
    int ActualFileSize;               // Size of data stored in file
    int ReferenceCount;               // Number of active references to file
    int Permission;                   // File permission
    char *Buffer;                     // Pointer to actual file data
    struct Inode *next;               // Pointer to next inode
};
 
typedef struct Inode INODE;            // Alias for Inode
typedef struct Inode* PINODE;          // Pointer to Inode
typedef struct Inode** PPINODE;        // Pointer to pointer of Inode

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     FileTable
//  Discription:        Holds the information about the  opened file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;                   // Current read pointer
    int WriteOffset;                  // Current write pointer
    int Mode;                         // Mode of file (READ, WRITE)
    PINODE ptrinode;                  // Pointer to inode of file

};

typedef FileTable FILETABLE;          // Alias for FileTable
typedef FileTable * PFILETABLE;       // Pointer to FileTable

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name:     UAREA
//  Discription:        Holds the information about the process
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];              // Name of the process
    PFILETABLE UFDT[MAXOPENFILES];     // Table of open files
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Global Variables or objects used in project
//   
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;                    // Boot block object
SuperBlock superobj;                  // Super block object
UAREA uareaobj;                       // User area object

PINODE head = NULL;                   // Head of inode linked list


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function Of The Project
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{


    return 0;                         // Program ends here
}
