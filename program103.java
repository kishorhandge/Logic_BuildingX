// OOP DESIGN
class ArrayX
{
    public int Arr[];
    public int iSize=0;

    public ArrayX(int no)
    {
        iSize=no;
        Arr=new int [iSize];
    }
}

class program103 
{
    public static void main(String A[]) 
    {
        ArrayX aobj1=new ArrayX(5);
        ArrayX aobj2=new ArrayX(7);
        ArrayX aobj3=new ArrayX(3);
    }
}
