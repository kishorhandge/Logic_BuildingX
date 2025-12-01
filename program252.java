import java.util.*;

class StringX
{
    public String Update(String str)
    {
        char Arr[] = str.toCharArray();

        Arr[0] = '_';

        String Temp = new String(Arr);

        return Temp;

    }
}
class program252
{
    public static void main(String A[]) 
    {   
        String sRet = null;

        Scanner scanobj = new Scanner(System.in); 
        
        System.out.println("Enter  String :");
        String sobj = scanobj.nextLine();

        StringX strobj = new StringX();

        sRet = strobj.Update(sobj);

        System.out.println("Updated String  is :"+sRet);

    }
}