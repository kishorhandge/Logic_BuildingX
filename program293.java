import java.util.*;

class program293
{
    public static void main(String A[]) 
    {
        int Arr[] = {45, 21, 90, 54, 78};

        // Using foreach loop to print original array
        for (int no : Arr)
        {
            System.out.println(no);
        }

        // Sorting the array
        Arrays.sort(Arr);

        System.out.println("Array after sorting");

        // Printing sorted array
        for (int no : Arr)
        {
            System.out.println(no);
        }
    }
}
