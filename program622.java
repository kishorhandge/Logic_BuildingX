import java.util.Scanner;

class program622
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

            // if(iDigit == 0)
            // {
            //     Count++;
            // }
            Count = Count + iDigit;   
            No = No/2;
        }
        System.out.println("Number of 0's in Data is : "+Count);

    }
    
}

/*  
----------------------------------------------- 8421-----------                                            
    Decimal             Hexadecimal             Binary
--------------------------------------------------------------------
    0                       0                   0000
    1                       1                   0001
    2                       2                   0010                   
    3                       3                   0011
    4                       4                   0100
    5                       5                   0101
    6                       6                   0110
    7                       7                   0111
    8                       8                   1000
    9                       9                   1001
    10                      a                   1010
    11                      b                   1101
    12                      c                   1100
    13                      d                   1101
    14                      e                   1110
    15                      f                   1111
------------------------------------------------------------------------





*/
