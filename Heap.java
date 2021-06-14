package Heap;
import java.util.*;
public class Heap {
    Scanner scanner=new Scanner(System.in);
    int[] heap;
    int n=-1;
    Heap(){
        heap=new int[50];
    }
    void insertMax(int data){
        n++;
        heap[n]=data;
        int i=n,parent,temp;
        while(i>0){
            parent=i/2;
            if(heap[parent]<heap[i]){
                temp=heap[parent];
                heap[parent]=heap[i];
                heap[i]=temp;
            }
            else{
                break;
            }
            i=parent;
        }
    }
    void display(){
        for(int i=0;i<=n;i++){
            System.out.print(heap[i]+" ");
        }
        System.out.println();
    }
    void insertMin(int data){
        int i,temp,parent;
        n++;
        heap[n]=data;
        i=n;
        while(i>0){
            parent=i/2;
            if(heap[parent]>heap[i]){
                temp=heap[i];
                heap[i]=heap[parent];
                heap[parent]=temp;
            }
            else{
                break;
            }
            i=parent;
        }
    }
    void deleteMax(){
        if(n==-1){
            System.out.println("Heap empty...");
            return;
        }
        int temp,parent=0,i=0;
        heap[parent]=heap[n];
        n--;
        while(i<=n){
            parent=(i-1)/2;
            if(heap[parent]<heap[i]){
                temp=heap[i];
                heap[i]=heap[parent];
                heap[parent]=temp;
            }
            i++;
        }
    }
    void deleteMin(){
        if(n==-1){
            System.out.println("Heap empty...");
            return;
        }
        int parent=0,i=0;
        int temp;
        System.out.println(heap[0]+" deleted...");
        heap[parent]=heap[n];
        n--;
        while(i<=n){
            parent=(i-1)/2;
            if(heap[parent]>heap[i]){
                temp=heap[parent];
                heap[parent]=heap[i];
                heap[i]=temp;
            }
            i++;
        }
    }
    void findParent(int e){
        int index=-1;
        for(int i=0;i<n;i++){
            if(heap[i]==e){
                index=i;
            }
        }
        if(index==-1){
            System.out.println("No such element found...");
            return;
        }
        System.out.println(heap[(index-1)/2]);
    }
    void findChildren(int e){
        int index=-1;
        for(int i=0;i<n;i++){
            if(heap[i]==e){
                index=i;
            }
        }
        if(index==-1){
            System.out.println("No such element found...");
            return;
        }
        if((2*index+1)>n){
            System.out.println("No child...");
            return;
        }
        if(2*index+1<=n) {
            System.out.println("Left child : " + heap[(index * 2) + 1]);
        }
        if(2*index+2<=n) {
            System.out.println("Right child : " + heap[(index * 2) + 2]);
        }
    }
    void processHeap(){
        int flag=1,c,e;
        while(flag==1){
            System.out.println("-----MENU-----");
            System.out.println("1.Insert\n2.Display\n3.Delete\n4.Find Parent\n5.Find children\n0.Exit");
            c=scanner.nextInt();
            switch(c){
                case 1:
                    System.out.println("Enter the element : ");
                    insertMin(scanner.nextInt());
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    deleteMin();
                    break;
                case 4:
                    System.out.println("Enter the number : ");
                    findParent(scanner.nextInt());
                    break;
                case 5:
                    System.out.println("Enter the number : ");
                    findChildren(scanner.nextInt());
                    break;
                case 0:
                    flag=0;
                    break;
                default:
                    System.out.println("Invalid choice...");
            }
        }
    }
    public static void main(String[] args){
        Heap obj=new Heap();
        obj.processHeap();
    }
}
