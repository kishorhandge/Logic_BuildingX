
import java.util.*;

class program811
{   
    
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the Number Rows in theatre");
        int R = sobj.nextInt();

        System.out.println("Enter the Number Columns in theatre");
        int C = sobj.nextInt();

        if(R <= 0 || C <= 0)
        {
            System.out.println("Invalid Input");
            return;
        }

        int Seats[][] = new int[R][C];
        int i = 0 ,j = 0;

        System.out.println("Enter booking details : (0/1)");

        for(i = 0 ;i<R;i++)
        {   
            System.out.println("Enter details of rows :" +(i+1));

            for(j = 0;j<C;j++)
            {
                Seats[i][j] = sobj.nextInt();

                if(Seats[i][j] != 0 && Seats[i][j] != 1)
                {
                    System.out.println("Invalid input");
                    return;
                }
            }
        }

        int TotalBooked = 0;
        int MaxBookedinRow = 0;
        int RowwithMax = 0;
        boolean FullRowExists = false;

        int RowBooked = 0;

        for(i = 0;i<R;i++)
        {   
            RowBooked = 0;

            for(j = 0;j<C;j++)
            {
                if(Seats[i][j] == 1)
                {
                    TotalBooked++;
                }

                RowBooked = RowBooked + Seats[i][j];
            }

            if(RowBooked > MaxBookedinRow)
            {
                MaxBookedinRow = RowBooked;
                RowwithMax = i;
            }

            if(RowBooked == C)
            {
                FullRowExists = true;
            }
        }

        System.out.println("Total booked seats : "+TotalBooked);

        System.out.println("Row with maximum booking : "+(RowwithMax + 1));

        if(FullRowExists == true)
        {
            System.out.println("Full row exists : Yes");

        }
        else
        {
            System.out.println("Full row exists : No");
        }

    }
}