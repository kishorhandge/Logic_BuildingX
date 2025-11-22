import java.util.*;
// OOP DESIGN
class ArrayX
{
    private int Arr[];
    private int iSize;

    public ArrayX(int no)
    {   
        System.out.println("Inside constructor");
        
        iSize=no;
        Arr=new int [iSize];  //alloacte the resources
    }

    public void accept()
    {
        Scanner sobj = new Scanner(System.in);
        int i=0;

        System.out.println("Enter the elements of array: ");

        for(i = 0;i < Arr.length;i++)
        {
            Arr[i] = sobj.nextInt();
        }

    }

    public void Display()
    {
        System.out.println("Elements of the array are:");

        int i=0;

        for(i = 0;i < Arr.length;i++)
        {
            System.out.println(Arr[i]);
        }
    }

    public float Average()
    {
        int i=0,iSum=0;

        for(i=0;i<Arr.length;i++)
        {
            iSum=iSum+Arr[i];
        }

        return iSum/iSize;
    }

}//End  of ArrayX class

class program108
{
    public static void main(String A[]) 
    {   
        float fRet=0.0f;

        ArrayX aobj1=new ArrayX(5);
        aobj1.accept();
        aobj1.Display();

        fRet = aobj1.Average();

        System.out.println("Average is : "+fRet);
       
    }
}
