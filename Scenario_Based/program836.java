
/*
A Disarium number is a number in which
the sum of its digits powered with their
respective positions is equal to the number itself.

Example:
135 is a Disarium number because
1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135.
*/

import java.util.*;

class program836
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iDigit = 0,iCount = 0,iTemp = 0,iSum = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

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
            System.out.println(iTemp + " is a Disarium Number");
        }
        else
        {
            System.out.println(iTemp + " is Not a Disarium Number");
        }

    }
}