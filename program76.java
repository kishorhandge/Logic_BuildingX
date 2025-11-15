import java.io.*;

class program76
{   //Not a Good programming
    public static void main(String Arr[]) throws IOException
    {
        int iNo=0;
        int i=0;

        BufferedReader bobj=new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter Number: ");

        iNo= Integer.parseInt(bobj.readLine());
         
        for(i=1;i<=(iNo/2);i++)
        {
            if((iNo % i) == 0)
            {
                System.out.println(i);
            }
        }
    }
}
