
import java.util.*;

class program817
{   
    public static boolean CheckStrong(int iNo)
    {   
        int iFact = 0, i = 0,iTemp = 0,iSum = 0,iDigit = 0;

        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit  = iNo % 10;
           
            for(iFact = 1,i = 1; i<= iDigit; i++)
            {
                iFact = iFact * i;
            }

            iSum = iSum + iFact;

            iNo = iNo/10;
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
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        bRet = CheckStrong(iNo);

        if(bRet == true)
        {
            System.out.println(iNo + " is a Strong Number");
        }
        else
        {
            System.out.println(iNo +" is not a Strong Number");
        }

        sobj.close();
    }
}