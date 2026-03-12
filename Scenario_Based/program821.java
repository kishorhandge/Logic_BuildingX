
import java.util.*;

class program821
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int x = 0, y = 0, i = 0,iPow = 0;

        System.out.println("Enter the Base:");
        x = sobj.nextInt();

        System.out.println("Enter the exponent (power):");
        y = sobj.nextInt();

        // x = 5 y = 3 -->125

        for(iPow = 1,i = 1;i<=y;i++)
        {
            iPow = iPow * x;
        }

        System.out.println(iPow);

        sobj.close();
    }
}