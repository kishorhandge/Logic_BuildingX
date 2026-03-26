
import java.util.*;

class Student
{
    public String Name;
    public int Marks;

    public Student(String a , int b)
    {
        this.Name = a;
        this.Marks = b;
    }

    @Override
    public String toString()
    {
        return  this.Name+ " : " + this.Marks;
    }

}

class program889
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
        String name = null;
        
        for(Student s : aobj)
        {   
            if(s.Marks > iMax)
            {
                iMax = s.Marks;
                name = s.Name;
                
            }
            
        }
        System.out.println(name+" : "+ iMax);
        // System.out.println("Highest student details : "+);

        aobj.clear();

    }
}

