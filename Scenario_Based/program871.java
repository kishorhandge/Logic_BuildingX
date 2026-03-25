/*
    0   1   2   3   4   5   6   7   8   9....
    a   b   c   d   e   f   g   h   i   j.....
    97  98  99  100 101 102 103 104 105 106 ....



*/

import java.util.Scanner;



class program871
{   
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter the String :");
        str = sobj.nextLine();

        char Arr[] = str.toCharArray();

        int Count[] = new int[26];

        for(int i = 0;i<Arr.length;i++)
        {
            System.out.println((int)Arr[i]);
        }
 
    }
}

