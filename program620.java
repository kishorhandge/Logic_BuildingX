import java.util.Scanner;

class program620
{
    public static void main(String A[])
    {   
        int iDigit = 0;
        int Count = 0;

       Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Number:");
        int No = sobj.nextInt();
        
        while(No != 0)
        {
            iDigit = No % 2;

            // if(iDigit == 1)
            // {
            //     Count++;
            // }
            Count = Count + iDigit;
            No = No/2;
        }
        System.out.println("Number of 1's in Data is : "+Count);

    }
    
}
