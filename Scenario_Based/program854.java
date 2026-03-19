import java.util.Scanner;

class program854
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

       for(String s : Arr)
       {
            System.out.println(s);
       }    //its always starts from first element and ends at last element (restricted loop)
    }
}

