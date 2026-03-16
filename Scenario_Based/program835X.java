
/*
A Sunny number is a number for which
the next number is a perfect square.

Example:
8 is a Sunny number because
8 + 1 = 9 and 9 is a perfect square.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckSunny(int iNo)
    { 
        iNo++;

       int Ans = (int)Math.sqrt(iNo);

       if(iNo == (Ans * Ans))
       {
            return true;
       }
       else
       {
            return false;
       }
    }
}

class program835X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckSunny(iNo);

       if(bRet == true)
       {
            System.out.println((iNo) + " is a Sunny Number");
       }
       else
       {
        System.out.println((iNo) + " is Not a Sunny Number");
       }

       sobj.close();

    }
}