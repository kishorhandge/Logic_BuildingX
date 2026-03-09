
import java.util.*;

class program799
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int Units = 0;
        int Amount = 0;

        System.out.println("Enter the Unit");
        Units = sobj.nextInt();

        if(Units < 0)
        {
            System.out.println("Unit Cannot be Negative!");
        }

        if(Units <= 100)
        {
            Amount = Units * 5;
            
        }

        else if(Units <= 200)
        {
            Amount = (100 * 5) + ((Units - 100) * 7);
             
        }

        else if(Units > 200)
        {
            Amount = (500 + 700) + ((Units - 200) * 10);
            
        }

        System.out.println("Total Units Consumed is : "+ Units);
        System.out.println("Electricity Bill is : "+Amount);

        sobj.close();

    }
}