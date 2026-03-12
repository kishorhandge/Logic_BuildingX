
/*
An Armstrong number is a number that is equal to 
the sum of its digits each raised to the power 
of the total number of digits.

153 --> yes
*/
import java.util.*;

class program823
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        int iCount = 0,iDigit = 0,iTemp = 0,iSum = 0,iPow = 0,iCountTemp = 0;

        iTemp = iNo;

        //count number of digits
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iCount++;
            iNo = iNo / 10;
        }

        iNo = iTemp ;
        iCountTemp = iCount;

        // y = iCount
        // x = iDigit

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iPow = 1;

            //count power
            while(iCount != 0)
            {
                iPow = iPow * iDigit;
                iCount--;
            }
            iCount = iCountTemp;

            iSum = iSum + iPow;
            iNo = iNo / 10;
        }

        if(iSum == iTemp)
        {
            System.out.println(iTemp + " is a Armstrong Number");
        }
        else
        {
            System.out.println(iTemp + " is Not a Armstrong Number");
        }

        sobj.close();
    }
}