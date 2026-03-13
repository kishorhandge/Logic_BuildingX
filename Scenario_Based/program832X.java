
/*
An Automorphic number is a number whose square 
ends with the same digits as the number itself.

Example:
25 is an Automorphic number because
25^2 = 625 and it ends with 25.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckAutomorphic(int iNo)
    {   
        int iSqre = 0,iTemp = 0,iCount = 0,iDenom = 0;

        iTemp = iNo;

        iSqre = iNo * iNo;

        while(iNo != 0)
        {
            iCount++;
            iNo = iNo / 10;
        }

        iDenom = (int)Math.pow(10, iCount);

        if(iSqre % iDenom == iTemp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class program832X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckAutomorphic(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a Automorphic Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Automorphic Number");
        }
    }
}