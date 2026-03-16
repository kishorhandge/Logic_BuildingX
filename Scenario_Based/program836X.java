
/*
A Disarium number is a number in which
the sum of its digits powered with their
respective positions is equal to the number itself.

Example:
135 is a Disarium number because
1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckDisarium(int iNo)
    {   
        int iDigit = 0,iCount = 0,iTemp = 0,iSum = 0;

        iTemp = iNo;

        while(iNo != 0)
        {
            iCount++;
            iNo = iNo/ 10;
        }

        iNo = iTemp;

        //135
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + ((int)Math.pow(iDigit ,iCount));
            iCount--;

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

class program836X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckDisarium(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a Disarium Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Disarium Number");
        }

        sobj.close();

    }
}