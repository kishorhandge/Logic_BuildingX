
/*
A Trimorphic number is a number whose cube 
ends with the same digits as the number itself.

Example:
4 is a Trimorphic number because
4^3 = 64 and it ends with 4.
*/


import java.util.*;

class program837
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iCube = 0,iTemp = 0,iCount = 0,iDenom = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

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
            System.out.println(iTemp + " is a Triomorphic Number");
        }
        else
        {
            System.out.println(iTemp + " is Not a Triomorphic Number");
        }
    }
}