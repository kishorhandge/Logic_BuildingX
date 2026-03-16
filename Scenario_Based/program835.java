
/*
A Sunny number is a number for which
the next number is a perfect square.

Example:
8 is a Sunny number because
8 + 1 = 9 and 9 is a perfect square.
*/

import java.util.*;

class program835
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        iNo++;

       int Ans = (int)Math.sqrt(iNo);

       if(iNo == (Ans * Ans))
       {
            System.out.println((iNo - 1) + " is a Sunny Number");
       }
       else
       {
        System.out.println((iNo - 1) + " is Not a Sunny Number");
       }

    }
}