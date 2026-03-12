
/*
A Harshad number is a number that is divisible 
by the sum of its digits.

Example:
18 is a Harshad number because
1 + 8 = 9 and 18 is divisible by 9.
*/

import java.util.*;

class program828
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iSum = 0,iDigit = 0,iTemp = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }

        if(iTemp % iSum == 0)
        {
            System.out.println(iTemp +" is a harshad Number");
        }
        else
        {
            System.out.println(iTemp + " is not a harshad Number");
        }
       
        sobj.close();
    }
}