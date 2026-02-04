import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

class program577
{
    public static void main(String A[]) throws Exception
    {   
        int iRet = 0;
        String str = null;

        File fobjSrc = null;
        File fobjDest = null;
        
        boolean bRet = false;
        String FileNameSrc = null;
        String FileNameDest = null;

        byte Buffer[] = new byte[1024];

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of Source file :");
        FileNameSrc = sobj.nextLine();

        System.out.println("Enter the name of Destination file :");
        FileNameDest = sobj.nextLine();

        fobjSrc = new File(FileNameSrc);

        if(fobjSrc.exists())
        {   
            fobjDest = new File(FileNameDest);

            fobjDest.createNewFile();
           

           FileInputStream fiobj = new FileInputStream(fobjSrc);
           FileOutputStream foobj = new FileOutputStream(fobjDest);

            while((iRet = fiobj.read(Buffer)) != -1)
            {   
                //System.out.print(str);  

                foobj.write(Buffer,0,iRet);
            }

            System.out.println("File Copied Succesfully.");   
            
            fiobj.close();
            foobj.close();
        }
        else
        {
            System.out.println("There is no Such Source file");
        }
        
        sobj.close();
    }
}