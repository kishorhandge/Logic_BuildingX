import java.util.*;

class Number
{
    public long CalculateFactorial(int iNo)
    {   
        int i=0;
        long iFact=1;

        if(iNo<0)
        {
            iNo=-iNo;
        }
        
        i=1;
        while(i<=iNo)       //Change
        {
            iFact=iFact*i;
            i++;
        }

        return iFact;
        
    }
} //End Of Number Class

class program89
{
    public static void main(String Arr[]) 
    {
        int iValue=0;
        long iRet=0;                //Important
          
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter Number: ");
        iValue=sobj.nextInt();

        Number nobj=new Number();
        iRet=nobj.CalculateFactorial(iValue);

        System.out.println("Factorial is :"+iRet);

        //Important
        
        sobj = null;
        nobj = null;

        System.gc();
        
    }
}
