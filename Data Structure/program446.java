
class node
{
    public int data;
    public node next;

    public node(int no)     //IMPORTANT
    {
        this.data = no;
        this.next = null;
    }

}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL() 
    {   
        System.out.println("Object of SinglyLL gets created");

        this.first = null;
        this.iCount = 0;
        
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        //Changed Code

        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        // if(first == null)
        // {
        //     this.first = newn;
        // }
        // else
        // {
        //     newn.next = this.first;
        //     this.first = newn;
        // }

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        //Changed Code

        newn = new node(no);

        if(first == null)
        {
            this.first = newn;
        }
        else
        {   
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
             
        }

        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
       else
        {
            this.first = this.first.next;

        }

        this.iCount--;
        System.gc();
    }

    public void DeleteLast()
    {   
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp =this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            
            temp.next = null;
           

        }
       
        this.iCount--;
        System.gc();
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no,int pos)
    {   
        int iCnt = 0;

        node temp = null;
        node newn = null;

        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == this.iCount + 1)
        {
            InsertLast(no);
        }
        else 
        {   
            newn = new node(no);

            temp =this.first;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;

            temp.next = newn;

            this.iCount++;

        }
    }


    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;

        node temp = null;

        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            DeleteLast();
        }
        else 
        {   
            temp =this.first;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            System.gc();

            this.iCount--;

        }
    }
    
}

class program446
{
    public static void main(String Arr[]) 
    {
        SinglyLL obj = null;
        int iRet = 0;


        obj = new SinglyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);

        obj.InsertAtPos(123, 4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);

        obj.DeleteAtPos(3);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of Nodes are:"+iRet);


        //Important For Memory Dallocation

        obj = null;
        System.gc();
    }
    
}
   