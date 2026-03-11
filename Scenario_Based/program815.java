
import java.util.*;

class program815
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int iNo = 0 , iFact = 0, i = 0;

        System.out.println("Enter the Number:");
        iNo = sobj.nextInt();

        //3! -> 3 * 2 * 1 = 6

        iFact = 1;

        for(i = 1;i <=iNo ;i++)
        {
            iFact = iFact * i;
        }

        System.out.println("Factorial is :"+iFact);

        
    }
}