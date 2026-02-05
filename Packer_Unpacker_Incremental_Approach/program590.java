import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;


class program590
{
    public static void main(String A[]) throws Exception
    {   
        int iRet = 0;
        byte Buffer[] = new byte[1024];

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of folder :");
        String FolderName = sobj.nextLine();

        System.out.println("Enter the name of Packed file :");
        String PackedName = sobj.nextLine();


        File fobj = new File(FolderName);

        if((fobj.exists()) && (fobj.isDirectory()))
        {   
            File packobj = new File(PackedName);

            packobj.createNewFile();

            FileOutputStream foobj = new FileOutputStream(packobj);

            FileInputStream fiobj = null;

            System.out.println("Folder is present");

            File fArr[] = fobj.listFiles();

            System.out.println("Number of files in the folder are: "+fArr.length);

            for(int i = 0;i < fArr.length; i++)
            {   
                fiobj = new FileInputStream(fArr[i]);   

                System.out.println("File name : "+fArr[i].getName()+ "      File size : "+fArr[i].length()+ " Bytes");
                

                if(fArr[i].getName().endsWith(".txt"))
                {
                    while((iRet = fiobj.read(Buffer)) != -1)
                    {
                        foobj.write(Buffer,0,iRet);
                    }
                }
               

                fiobj.close();
            }

            foobj.close();
        }
        else
        {
            System.out.println("There is no such folder");
        }
    }
}