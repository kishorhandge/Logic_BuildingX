/*
    input: 8
    output:1    A   3   B   5   C   7   D

    index: 1    2   3   4   5   6   7   8   
    

*/
import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        //int i = 65;
        char ch ='A';

        for(iCnt = 1;iCnt<=iNo;iCnt++)
        {
            if((iCnt%2) == 1)
            {
                System.out.printf("%d\t",iCnt);  
            }
            else
            {
                System.out.printf("%c\t",ch);
                ch++;
            }
            
        }
        
        System.out.println();

    }
}
class program177
{
    public static void main(String A[]) 
    {   
        int iValue = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the frequency: ");
        iValue = sobj.nextInt();

        Pattern pobj = new Pattern();

        pobj.Display(iValue);


    }
}
