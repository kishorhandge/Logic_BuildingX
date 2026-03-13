
/*
A Spy number is a number where the sum 
of its digits is equal to the product 
of its digits.

Example:
1124 is a Spy number because
1 + 1 + 2 + 4 = 8
and
1 × 1 × 2 × 4 = 8.
*/

import java.util.*;

class program833
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iSum = 0,iTemp = 0,iCount = 0,iMult = 0,iDigit = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        iTemp = iNo;

        iMult = 1;

        while(iNo != 0)
        {   
            iDigit = iNo % 10;
            
            iSum = iSum + iDigit;
            iMult = iMult * iDigit;
            
            iNo = iNo / 10;
        }

        if(iSum == iMult)
        {
            System.out.println(iTemp + " is a Spy Number");
        }
        else
        {
            System.out.println(iTemp + " is Not a Spy Number");
        }
    }
}