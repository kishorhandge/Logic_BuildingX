import java.util.Scanner;

//Input -- >  india is my country i live in INDIA
//Output -- > bharat is my country i live in bharat


class program870
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

        StringBuffer finalstr = new StringBuffer();

       for(int i = 0;i < Arr.length;i++)
       {    
            if(Arr[i].equalsIgnoreCase("india"))
            {
                finalstr.append("bharat"+" ");
            }
            else
            {
                finalstr.append(Arr[i]+" ");
            }
       }  

       System.out.println(finalstr);
         
    }
}

