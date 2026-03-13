
/*
A Neon number is a number where the sum 
of the digits of its square is equal 
to the original number.

Example:
9 is a Neon number because
9^2 = 81 and 8 + 1 = 9.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckNeon(int iNo)
    {   
        int iDigit = 0,iSum = 0,iTemp = 0;

        iTemp = iNo;

        iNo = iNo * iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;

            iSum = iSum + iDigit;

            iNo = iNo / 10;
        }

        if(iSum == iTemp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class program831X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckNeon(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a neon number");
        }
        else
        {
            System.out.println(iNo + " is  not a neon number");
        }

        sobj.close();

    }
}