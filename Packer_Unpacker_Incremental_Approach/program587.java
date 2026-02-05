 
class program587
{
    public static void main(String A[]) throws Exception
    {   
        String str = "Hello";

        byte Arr[] = str.getBytes();

        byte key = 0x11;

        System.out.println("Orignal data : "+str);

        for(int i = 0;i<Arr.length;i++)
        {
            Arr[i] = (byte)(Arr[i] ^ key);
        }

        String output = new String(Arr);

        System.out.println("Encrypted data : "+output);
    }
}
