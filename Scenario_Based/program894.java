
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

class program894
{   
    public static void main(String A[])  
    {   
        ArrayList <Student> database = new ArrayList <Student> ();

        Student s1 = new Student("Sagar", 90);
        Student s2 = new Student("Rahul", 80);
        Student s3 = new Student("Pooja", 92);
        Student s4 = new Student("Amit", 72);

        database.add(s1);
        database.add(s2);
        database.add(s3);
        database.add(s4);

        String FileName = "Marvellous.csv";

        try(FileWriter fwobj = new FileWriter(FileName))
        {   
            
            fwobj.write("name,marks\n");

            for(Student s : database)
            {   
                fwobj.write(s.getName() + "," + s.getMarks() + "\n");
                
            }
        }
        catch (Exception eobj)
        {
            System.out.println("Exception occured");
        }
        finally
        {
            System.out.println("Data gets stored succesfully");

            database.clear();
        }

    }
}

