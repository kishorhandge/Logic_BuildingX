
import java.util.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.io.*;


class Student
{
    private String Name;
    private int Marks;

    public Student(String a , int b)
    {
        this.Name = a;
        this.Marks = b;
    }

    public String getName()
    {
        return this.Name;
    }

    public int getMarks()
    {
        return this.Marks;
    }

    @Override
    public String toString()
    {
        return  this.Name+ " : " + this.Marks;
    }

}

class program895
{   
    public static void main(String A[])  
    {   
         

    }
}

