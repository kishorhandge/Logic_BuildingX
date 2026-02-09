import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

//Packing Final code
class program606
{
    public static void main(String A[]) throws Exception
    {   
        String Header = null;

        int iRet = 0;
        int i,j= 0;

        byte key = 0x11;

        byte Buffer[] = new byte[1024];
        byte bHeader[] = new byte[100];

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

                if(fArr[i].getName().endsWith(".txt"))
                {   
                    //Header formation

                    Header = fArr[i].getName() + " " + fArr[i].length();

                    for(j = Header.length();j<100;j++)
                    {
                        Header = Header + " ";
                    }

                    bHeader = Header.getBytes();

                    //Write header into packed file
                    foobj.write(bHeader,0,100);

                    //Read the data from input files from Marvellous folder
                    while((iRet = fiobj.read(Buffer)) != -1)
                    {   
                        //Encryption process

                        for(j = 0;j<iRet;j++)
                        {
                            Buffer[j] = (byte)(Buffer[j] ^ key);
                        }

                        //Write the files data into packed files
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