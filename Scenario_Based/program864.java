import java.util.Scanner;

class program864
{   
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter the String :");
        str = sobj.nextLine();

        StringBuffer sb = new StringBuffer(str);

        System.out.println(sb);
        System.out.println(sb.length());
        
    }
}

