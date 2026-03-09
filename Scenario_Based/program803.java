//0 1 1 2 3 5 8 13 21.... (fibonacci)
import java.util.*;

class program803
{
    public static void main(String A[])
    {   
        int iCnt = 0;

        long First = 0;
        long Second = 0;
        long Next = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number of elements in series:");
        int Size = sobj.nextInt();

        for(iCnt = 1,First = 0,Second = 1,Next = 0;iCnt <= Size;iCnt++)
        {
            System.out.println(First+" ");

            Next = First + Second;
            First = Second;
            Second = Next;
        }
        System.out.println();

        sobj.close();
    }
}