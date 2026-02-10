import java.util.Scanner;

class program619
{
    public static void main(String A[])
    {   
        int iDigit = 0;

       Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Number:");
        int No = sobj.nextInt();
        
        while(No != 0)
        {
            iDigit = No % 2;
            System.out.print(iDigit + "\t");
            No = No/2;
        }

    }
    
}
