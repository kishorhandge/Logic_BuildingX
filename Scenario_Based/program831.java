
/*
A Neon number is a number where the sum 
of the digits of its square is equal 
to the original number.

Example:
9 is a Neon number because
9^2 = 81 and 8 + 1 = 9.
*/

import java.util.*;

class program831
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iDigit = 0,iSum = 0,iTemp = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

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
            System.out.println(iTemp + " is a neon number");
        }
        else
        {
            System.out.println(iTemp + " is  not a neon number");
        }


    }
}