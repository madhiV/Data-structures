package Day1;
import java.util.Scanner;
class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}
public class LinkedList {
    Node temp,head=null,old,n;
    public void insert_begin(int data){
        temp=new Node(data);
        if(head==null){
            head=temp;
        }
        else{
            temp.next=head;
            head=temp;
        }
        System.out.println(data+" insertion success...\n");
    }
    public void insert_middle(int data,int pos){
        n=new Node(data);
        temp=head;
        if(pos==1){
            n.next=head;
        }
        else{
            while(pos!=1){
                pos--;
                old=temp;
                temp=temp.next;
            }
            old.next=n;
            n.next=temp;
        }
        System.out.println(data+" insertion success...\n");
    }
    public void insert_end(int val){
        n=new Node(val);
        temp=head;
        if(head==null){
            head=n;
        }
        else{
            while(temp!=null){
                old=temp;
                temp=temp.next;
            }
            old.next=n;
        }
        System.out.println(val+" insertion success...\n");
    }
    public void display(){
        temp=head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
        System.out.println();
    }
    public void deleteBegin(){
        if(head==null){
            System.out.println("No elements to delete...\n");
        }
        else{
            System.out.println(head.data+" deletion success...\n");
            head=head.next;
        }
    }
    public void deleteMiddle(int pos){
        temp=head;
        if(head==null){
            System.out.println("No elements to delete...\n");
        }
        else{
            old=temp;
            if(pos==1){
                head=head.next;
            }
            else{
                while(pos!=1){
                    old=temp;
                    temp=temp.next;
                    pos--;
                }
                old.next=temp.next;
            }
        }
        System.out.println(temp.data+" deletion success...\n");
    }
    public void deleteEnd(){
        temp=head;
        if(head.next==null){
            head=null;
        }
        else{
            while(temp.next!=null){
                old=temp;
                temp=temp.next;
            }
            old.next=null;
        }
    }
    public int count(){
        int c=0;
        temp=head;
        while(temp!=null){
            temp=temp.next;
            c++;
        }
        return c;
    }
    public int nthElement(int p){
        temp=head;
        while(p!=1){
            temp=temp.next;
            p--;
        }
        return temp.data;
    }
    public void deleteList(){
        head=null;
        System.out.println("List deletion success...\n");
    }
    public static void main(String[] args) {
        int c,e,f=1;
        LinkedList obj=new LinkedList();
        Scanner scanner=new Scanner(System.in);
        while(f==1){
            System.out.println("-----MENU-----\n");
            System.out.println("1.Insert at begining\n2.Insert at middle\n3.Insert at the end\n4.Delete at begining\n5.Delete at middle\n6.Delete at end\n7.Traverse\n8.Count the number of elements\n9.Find the nth number of element in the list\n10.Delete List\n0.Exit\n");
            System.out.println("Enter your choice : ");
            c=scanner.nextInt();
            switch(c){
                case 1:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    obj.insert_begin(e);
                    break;
                case 2:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    System.out.println("Enter the position to insert : ");
                    c=scanner.nextInt();
                    obj.insert_middle(e,c);
                    break;
                case 3:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    obj.insert_end(e);
                    break;          
                case 4:
                    obj.deleteBegin();
                    break;
                case 5:
                    System.out.println("Enter the position of the element to delete : ");
                    e=scanner.nextInt();
                    obj.deleteMiddle(e);
                    break;
                case 6:
                    obj.deleteEnd();
                    break;
                case 7:
                    obj.display();
                    break;
                case 8:
                    System.out.println("The number of elements in the list is : "+obj.count());
                    break;
                case 9:
                    System.out.println("Enter the position of the element to find : ");
                    e=scanner.nextInt();
                    System.out.println("The "+e+"th element of the list is : "+ obj.nthElement(e));
                    break;
                            
                case 10:
                    obj.deleteList();
                    break;
                case 0:
                    f=0;
                    break;
                default:
                    System.out.println("Invalid option");
            }
        }
    }
}
