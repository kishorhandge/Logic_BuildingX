
import java.util.*;

class program800
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int Amount = 0;
        String MemberShip = null;

        float DiscountAmount = 0.0f;
        float FinalAmount = 0.0f;

        System.out.println("Enter the purchase Amount :");
        Amount = sobj.nextInt();

        System.out.println("Enter the MemberShip Type (Premium or Regular):");
        MemberShip = sobj.next();

        if((Amount < 0) || ((MemberShip.equalsIgnoreCase("Premium") == false) && 
                            (MemberShip.equalsIgnoreCase("Regular") == false)))
        {
            System.out.println("Invalid Input");
            return;
        }

        
        if(Amount > 5000)   //20%
        {
            DiscountAmount = Amount* 0.2f;
        }
        else if(Amount > 2000) //10%
        {
            DiscountAmount = Amount * 0.1f;
        }
        else        //0%
        {
            DiscountAmount = 0.0f;
        }

        FinalAmount = Amount - DiscountAmount;

        if(MemberShip.equalsIgnoreCase("Premium"))
        {
            DiscountAmount = DiscountAmount  + (FinalAmount * 0.05f);
            FinalAmount = Amount - DiscountAmount;
        }

        System.out.println("Orignal Amount : "+Amount);

        System.out.println("Total Discount : "+DiscountAmount);

        System.out.println("Final Payble Amount: "+FinalAmount);

    }
}