
/*
An Automorphic number is a number whose square 
ends with the same digits as the number itself.

Example:
25 is an Automorphic number because
25^2 = 625 and it ends with 25.
*/

import java.util.*;

class program832
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iSqre = 0,iTemp = 0,iCount = 0,iDenom = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

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
            System.out.println(iTemp + " is a Automorphic Number");
        }
        else
        {
            System.out.println(iTemp + " is Not a Automorphic Number");
        }
    }
}