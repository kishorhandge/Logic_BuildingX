import java.util.Scanner;

class program862
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

        int iCount = 0;

       for(int i = 0;i < Arr.length;i++)
       {    
            if(Arr[i].equals("india") == true)
            {
                iCount++;
               
            }   
       }  
       System.out.println("Frequency of given word is : "+iCount); 
      
       
    }
}

