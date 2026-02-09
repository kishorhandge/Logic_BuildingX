
import java.io.File;
import java.util.Scanner;

//Unpacking code

class program607
{
    public static void main(String A[]) throws Exception
    {   
        //Variable creation
        Scanner sobj = null;
        String FileName = null;


        sobj = new Scanner(System.in);

        System.out.println("Enter the name of packed file :");
        FileName  = sobj.nextLine();

        File fpackobj = new File(FileName);

        if(fpackobj.exists() == false)
        {
            System.out.println("Error : There is no such packed file");
            return;
        }


    }
}