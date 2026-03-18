
class program850
{   
    
    public static void main(String A[])
    {   
        String str = "  india   is   my  country  ";

        System.out.println(str);
        str = str.trim();

        //str = str.replaceAll("\\s+", " ");    //IMPORTANT

        String Arr[] = str.split(" ");

        System.out.println(Arr.length);

    }
}