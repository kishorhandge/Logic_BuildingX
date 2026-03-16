
/*
A Trimorphic number is a number whose cube 
ends with the same digits as the number itself.

Example:
4 is a Trimorphic number because
4^3 = 64 and it ends with 4.
*/

import java.util.*;

class NumberX
{
    public static boolean CheckTrimorphic(int iNo)
    {   
        int iCube = 0,iTemp = 0,iCount = 0,iDenom = 0;

        iTemp = iNo;

        iCube = iNo * iNo * iNo;

        while(iNo != 0)
        {
            iCount++;
            iNo = iNo / 10;
        }

        iDenom = (int)Math.pow(10, iCount);

        if(iCube % iDenom == iTemp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class program837X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckTrimorphic(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a Triomorphic Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Triomorphic Number");
        }

        sobj.close();
    }
}