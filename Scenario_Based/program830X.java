
/*
A Palindrome number is a number that remains 
the same when its digits are reversed.

Example:
121 is a Palindrome number because
its reverse is also 121.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckPalindrome(int iNo)
    {   
        int iDigit = 0,iTemp = 0,iRev = 0;

        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = iRev * 10 + iDigit;
            iNo = iNo / 10;
        }

        if(iTemp == iRev)
        {
            return  true;
        }
        else
        {
            return false;
        }
    }
}

class program830X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckPalindrome(iNo);
        
        if(bRet == true)
        {
            System.out.println(iNo + " is a Palindrome Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Palindrome Number");
        }

        sobj.close();

    }
}