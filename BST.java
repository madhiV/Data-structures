import java.util.*;
public class BST {
    BNode root=null,temp,p;
    static Scanner scanner = new Scanner(System.in);
    BNode insert(BNode temp,int data){
        if(temp==null){
            temp=new BNode(data);
        }
        else if(temp.data>data){
            temp.left=insert(temp.left,data);
        }
        else if(temp.data<data){
            temp.right=insert(temp.right,data);
        }
        else{
            System.out.println("Cannot insert duplicate value ...");
        }
        return temp;
    }
    void inorderTraversal(BNode temp){
        if(temp==null){
            return;
        }
        inorderTraversal(temp.left);
        System.out.print(temp.data+" ");
        inorderTraversal(temp.right);
    }
    void DFS(BNode temp){
        if(temp==null){
            return;
        }
        System.out.print(temp.data+" ");
        inorderTraversal(temp.left);
        inorderTraversal(temp.right);
    }
    boolean search(BNode temp,int data){
        if(temp==null){
            return false;
        }
        if(temp.data>data){
            return search(temp.left,data);
        }
        if(temp.data<data){
            return search(temp.right,data);
        }
        return true;
    }
    void BFS(){
        temp=root;
        if(temp==null){
            return;
        }
        Queue<BNode> q=new LinkedList<BNode>();
        q.add(temp);
        while(q.size()>0){
            p=q.peek();
            q.remove();
            System.out.print(p.data+" ");
            if(p.left!=null){
                q.add(p.left);
            }
            if(p.right!=null){
                q.add(p.right);
            }
        }
        System.out.println();
    }
    int height(BNode temp){
        if(temp==null){
            return -1;
        }
        return 1+Math.max(height(temp.left),height(temp.right));
    }
    BNode delete(BNode temp,int data){
        if(temp.data>data){
            temp.left=delete(temp.left,data);
        }
        else if(temp.data<data){
            temp.right=delete(temp.right,data);
        }
        else if(temp.data==data){
            //Leaf node deletion
            if(temp.right==null && temp.left==null){
                return null;
            }
            //One child
            if(temp.left==null && temp.right!=null){
                return temp.right;
            }
            if(temp.left!=null && temp.right==null){
                return temp.left;
            }
            //Two children
            if(temp.left!=null && temp.right!=null){
                temp.data=minV(temp.right);
                temp.right=delete(temp.right,temp.data);
            }
        }
        return temp;
    }
    int minV(BNode temp){
        while(temp.left!=null){
            temp=temp.left;
        }
        return temp.data;
    }
    int maxV(BNode temp){
        while(temp.right!=null){
            temp=temp.right;
        }
        return temp.data;
    }
    void processTree(){
        int c,e,flag=1;
        while(flag==1){
            System.out.println("-----MENU-----");
            System.out.println("1.Insert\n2.Inorder traversal\n3.Search\n4.Delete\n5.Minimum value\n6.Maximum value\n7.BFS\n8.Height of the tree\n9.DFS\n0.Exit");
            System.out.println("Enter a choice : ");
            c=scanner.nextInt();
            switch(c){
                case 1:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    if(root==null){
                        root=new BNode(e);
                        break;
                    }
                    insert(root,e);
                    break;
                case 2:
                    inorderTraversal(root);
                    System.out.println();
                    break;
                case 3:
                    System.out.println("Enter the element : ");
                    e=scanner.nextInt();
                    if(search(root,e)){
                        System.out.println("Element present...");
                        break;
                    }
                    System.out.println("Element not found...");
                    break;
                case 4:
                    System.out.println("Enter the element to delete : ");
                    e=scanner.nextInt();
                    root=delete(root,e);
                    break;
                case 5:
                    if(root==null){
                        System.out.println("Tree empty...");
                        break;
                    }
                    System.out.println("The minimum Value is : "+minV(root));
                    break;
                case 6:
                    if(root==null){
                        System.out.println("Tree empty...");
                        break;
                    }
                    System.out.println("The maximum value : "+maxV(root));
                    break;
                case 7:
                    BFS();
                    break;
                case 8:
                    System.out.println("Height of the tree : "+height(root));
                    break;
                case 9:
                    DFS(root);
                    System.out.println();
                    break;
                case 0:
                    flag=0;
                    break;
                default:
                    System.out.println("Invalid choice ...");
            }
        }
    }
    public static void main(String[] args) {
        BST obj=new BST();
        obj.processTree();
    }
}
