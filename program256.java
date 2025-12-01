import java.util.*;

class StringX
{
    public String StrToggleX(String str)
    {   
        int iCnt = 0;
        char Arr[] = str.toCharArray();

       for(iCnt = 0;iCnt < Arr.length;iCnt++)
        {
            if((Arr[iCnt] >= 'a' && Arr[iCnt] <= 'z') )
            {
                Arr[iCnt] = (char)(Arr[iCnt] - 32);
            }
            else if(Arr[iCnt] >= 'A' && Arr[iCnt] <= 'Z' )
            {
                Arr[iCnt] = (char)(Arr[iCnt] + 32);
            }
        }

        return new String(Arr);                   //Change

    }
}
class program256
{
    public static void main(String A[]) 
    {   
        String sRet = null;
        Scanner scanobj = new Scanner(System.in); 
        
        System.out.println("Enter  String :");
        String sobj = scanobj.nextLine();

        StringX strobj = new StringX();

        sRet = strobj.StrToggleX(sobj);                 //Change (Not Prefarable)

        System.out.println("Updated String  is :"+sRet);

    }
}