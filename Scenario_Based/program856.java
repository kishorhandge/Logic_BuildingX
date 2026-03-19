import java.util.Scanner;

class program856
{   
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter the String :");

        //Step 0
        str = sobj.nextLine();

        //Step 1 
        str = str.trim();

        //Step 2
        str = str.replaceAll("\\s+", " ");

        //Step 3
        String Arr[] = str.split(" ");

        //Flexible loop
       for(int i = Arr.length - 1;i >= 0;i--)
       {
            System.out.println(Arr[i]);
       }   
    }
}

