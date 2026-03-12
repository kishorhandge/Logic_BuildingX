
/*
A Harshad number is a number that is divisible 
by the sum of its digits.

Example:
18 is a Harshad number because
1 + 8 = 9 and 18 is divisible by 9.
*/

import java.util.*;


class NumberX
{
    public static boolean CheckHarshad(int iNo)
    {   
        int iSum = 0,iDigit = 0,iTemp = 0;

        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }

        if(iTemp % iSum == 0)
        {
            return true;
        }
        else
        {
           return  false;
        }
    }

}

class program828X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckHarshad(iNo);

        if(bRet == true)
        {
            System.out.println(iNo +" is a harshad Number");
        }
        else
        {
            System.out.println(iNo + " is not a harshad Number");
        }
       
        sobj.close();
    }
}