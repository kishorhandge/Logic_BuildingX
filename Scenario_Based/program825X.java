
/*
An Armstrong number is a number that is equal to 
the sum of its digits each raised to the power 
of the total number of digits.

153 --> yes
*/
import java.util.*;


class NumberX

{
    public static boolean  CheckArmstrong(int iNo)
    {
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

            iNo = iTemp ;
            
                //count power
                    while(iNo != 0)
                    {
                    iDigit = iNo % 10;

                    iPow = (int)Math.pow(iDigit, iCount);

                    iSum = iSum + iPow;
                    iNo = iNo / 10;
                }
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

class program825X
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        NumberX nobj = new NumberX();

        bRet = nobj.CheckArmstrong(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a Armstrong Number");
        }
        else
        {
            System.out.println(iNo + " is Not a Armstrong Number");
        }

        sobj.close();
    }
}