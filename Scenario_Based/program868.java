import java.util.Scanner;

class program868
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

        StringBuffer sb = null;
        StringBuffer finalstr = new StringBuffer();

       for(int i = 0;i < Arr.length;i++)
       {    
            sb = new StringBuffer(Arr[i]);
            (finalstr.append(sb.reverse())).append(" ");   
       }  

       System.out.println(finalstr);
       System.out.println(finalstr.length());
       System.out.println(str.length());
       
        
    }
}

