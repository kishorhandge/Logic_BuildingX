//0 1 1 2 3 5 8 13 21.... (fibonacci)
import java.util.*;

class program804
{   
    public static long fibonacci(int N)
    {
        if(N <= 1)
        {
            return  N;
        }

        return fibonacci(N - 1) + fibonacci( N - 2);
    }
    public static void main(String A[])
    {   
        int iCnt = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number of elements in series:");
        int Size = sobj.nextInt();

        for(iCnt = 0;iCnt <= Size;iCnt++)
        {
            System.out.print(fibonacci(iCnt) + " ");
        }

        System.out.println();

        sobj.close();
    }
}