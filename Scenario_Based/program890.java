
import java.util.*;

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

class program890
{   
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        ArrayList <Student> aobj = new ArrayList <Student> ();

        Student s1 = new Student("Sagar", 90);
        Student s2 = new Student("Rahul", 80);
        Student s3 = new Student("Pooja", 92);
        Student s4 = new Student("Amit", 72);

        aobj.add(s1);
        aobj.add(s2);
        aobj.add(s3);
        aobj.add(s4);

        int iMax = 0;
        Student temp = null;
        
        for(Student s : aobj)
        {   
            if(s.getMarks() > iMax)
            {
                iMax = s.getMarks();
                temp = s;
                
            }
            
        }
        System.out.println("highest marks student details : "+temp);

        aobj.clear();

        

    }
}

