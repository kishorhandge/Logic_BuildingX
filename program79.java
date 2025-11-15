import java.util.*;

class Number
{
    public boolean  CheckPerfect(int iNo)
    {   
        int iCnt=0;
        int iSum=0;

        for(iCnt=1;iCnt<=(iNo/2);iCnt++)
        {
            if((iNo % iCnt) == 0)
            {
                iSum=iSum+iCnt;
            }
        }

        if(iSum == iNo)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
} //End Of Number Class

class program79
{
    public static void main(String Arr[]) 
    {
        int iValue=0;
        boolean bRet = false;
         
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number: ");
        iValue=sobj.nextInt();

        Number nobj=new Number();
        bRet=nobj.CheckPerfect(iValue);

        if(bRet == true)
        {
            System.out.println(iValue+ " is a perfect number");
        }
        else
        {
            System.out.println(iValue+" is not a perfect number");
        }

        //Important
        
        sobj = null;
        nobj = null;

        System.gc();
        
    }
}
