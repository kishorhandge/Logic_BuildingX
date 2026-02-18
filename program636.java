// 14th bit OFF
//8192-->0
//9820-->1628
// 1111  1111   1111   1111  1101 1111   1111   1111
//  f     f     f       f      d    f       f   f
//0xffffdfff

import java.util.Scanner;

class program636
{
    public static void main(String A[])
    {   
        int iNo = 0,iMask = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Number : ");
        iNo = sobj.nextInt();

        iMask = 0xffffdfff;

        iNo = iNo & iMask;

        System.out.println("Updated Number : "+iNo);


    }
    
}

 
