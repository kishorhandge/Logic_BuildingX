// iPos = 14
// iMask = 1
//  0000    0000    0000    0000    0000    0000    0000    0001

// iMask = iMask << (iPos -1)

//  0000    0000    0000    0000    0010    0000    0000    0000
//iMask = ~iMask
//  1111    1111    1111    1111    1101   1111    1111    1111


//Toggel Bit
//iPos = 5

// iNo =        0100    1101
//iMask =       0001    0000        ^
//-------------------------------------------
//  iNo =       0101    1101


// iNo =        0101    1101
//iMask =       0001    0000        ^
//-------------------------------------------
//  iNo =       0100    1101            

//input-->860 ,output-->988,ipos = 8
//input-->988 ,output-->860,ipos = 8

import java.util.Scanner;

class program638
{
    public static void main(String A[])
    {   
        int iNo = 0,iMask = 0x1,iPos = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Number : ");
        iNo = sobj.nextInt();

        System.out.println("Enter the Position : ");
        iPos = sobj.nextInt();

        iMask = iMask << (iPos -1);

        iNo = iNo ^ iMask;

        System.out.println("Updated Number : "+iNo);


    }
    
}

 
