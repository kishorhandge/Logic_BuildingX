import java.util.*;

class StringX
{
    public String Update(String str)
    {
        char Arr[] = str.toCharArray();

        Arr[0] = '_';

        return new String(Arr);                   //Change

    }
}
class program254
{
    public static void main(String A[]) 
    {   

        Scanner scanobj = new Scanner(System.in); 
        
        System.out.println("Enter  String :");
        String sobj = scanobj.nextLine();

        StringX strobj = new StringX();

        sobj = strobj.Update(sobj);                 //Change (Not Prefarable)

        System.out.println("Updated String  is :"+sobj);

    }
}