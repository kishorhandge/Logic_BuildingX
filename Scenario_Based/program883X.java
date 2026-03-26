

import java.util.Scanner;

class program883X
{   
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter the String :");

        str = sobj.nextLine();
 
        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Arr[] = str.split(" ");

        int i = 0;

        StringBuffer sb = new StringBuffer(Arr[i]);
        String finalstr = null;

        sb.reverse();

        for(i = 0;i < Arr.length;i++)
       {    
            sb = new StringBuffer(Arr[i]);
            sb.reverse();
       }  
       System.out.println(sb);

       if(str.equals(sb.toString()))
       {
            System.out.println("String is palindrome");
       }
       else
       {
            System.out.println("String is not palindrome");
       }

       sobj.close();
 
    }
}

