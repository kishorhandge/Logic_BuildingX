import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;


class program603
{
    public static void main(String A[]) throws Exception
    {   
        String Header = null;

        int iRet = 0;
        int i,j = 0;

        byte key = 0x11;

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

            for(i = 0;i < fArr.length; i++)
            {   
                fiobj = new FileInputStream(fArr[i]);   

                
                Header = fArr[i].getName() + " " + fArr[i].length();

                System.out.println(Header);

                if(fArr[i].getName().endsWith(".txt"))
                {
                    /*while((iRet = fiobj.read(Buffer)) != -1)
                    {   
                        //Encryption process

                        for(j = 0;j<iRet;j++)
                        {
                            Buffer[j] = (byte)(Buffer[j] ^ key);
                        }

                        foobj.write(Buffer,0,iRet);
                    }*/
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