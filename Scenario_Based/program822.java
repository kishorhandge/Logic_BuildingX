
import java.util.*;

class program822
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        int x = 0, y = 0,iPow = 0;

        System.out.println("Enter the Base:");
        x = sobj.nextInt();

        System.out.println("Enter the exponent (power):");
        y = sobj.nextInt();

        // x = 5 y = 3 -->125

        iPow = 1;
        
        while(y != 0)
        {
            iPow = iPow * x;
            y--;
        }

        System.out.println(iPow);

        sobj.close();
    }
}