//0 1 1 2 3 5 8 13 21.... (fibonacci)
import java.util.*;

class program806
{   
    
    public static void main(String A[])
    {   
        int iCnt = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number of elements in series:");
        int Size = sobj.nextInt();

        long dp[] = new long[Size + 1];

        dp[0] = 0;
        dp[1] = 1;

        for(iCnt = 2;iCnt < Size;iCnt++)
        {
            dp[iCnt] = dp[iCnt - 1] + dp[iCnt - 2];
            
        }

        for(iCnt = 0;iCnt < Size;iCnt++)
        {
            System.out.print(dp[iCnt]+" ");
        }

        sobj.close();
    }
}