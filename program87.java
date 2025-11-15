import java.util.*;

class Number
{
    public int CalculateFactorial(int iNo)
    {   
        int i=0;
        int iFact=1;

        if(iNo<0)
        {
            iNo=-iNo;
        }

        for(i=1;i<=iNo;i++)
        {
            iFact=iFact*i;
        }

        return iFact;
        
    }
} //End Of Number Class

class program87
{
    public static void main(String Arr[]) 
    {
        int iValue=0,iRet=0;
          
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
