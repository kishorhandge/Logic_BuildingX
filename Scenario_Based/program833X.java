
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

class NumberX
{
    public static boolean CheckAutomorphic(int iNo)
    {   
        int iSum = 0,iTemp = 0,iCount = 0,iMult = 0,iDigit = 0;

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
            return true;
        }
        else
        {
            return  false;
        }
    }
}

class program833X
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
            System.out.println(iNo + " is a Spy Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Spy Number");
        }

        sobj.close();
    }
}